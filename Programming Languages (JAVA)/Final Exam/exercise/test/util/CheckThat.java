package exercise.test.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Arrays;
import java.util.Map;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CheckThat {
	public static enum Staticness { STATIC, NOT_STATIC }
	public static enum Modifiability { MODIFIABLE, NOT_MODIFIABLE }

	private enum ClassType { A_CLASS, AN_INTERFACE, AN_ENUM }
	private enum InspectedMember { CONSTRUCTOR, METHOD, FIELD }

	public static enum Visibility {
		PUBLIC(Modifier::isPublic, "publikus", "public"),
		PACKAGE_PRIVATE(mod -> Stream.<Predicate<Integer>>of(Modifier::isPublic, Modifier::isProtected, Modifier::isPrivate).noneMatch(cond -> cond.test(mod)), "félnyilvános", "package private"),
		PROTECTED(Modifier::isProtected, "protected", "protected"),
		PRIVATE(Modifier::isPrivate, "privát", "private");

		public Predicate<Integer> condition;
		public String huName;
		public String enName;

		Visibility(Predicate<Integer> condition, String huName, String enName) {
			this.condition = condition;
			this.huName = huName;
			this.enName = enName;
		}

		public static Visibility getVisibility(int mod) {
			return Arrays.stream(values()).filter(v -> v.condition.test(mod)).findFirst().get();
		}
	}

	String className;
	Class<?> clazz;
	ClassType classType;

	InspectedMember inspectedMember;
	boolean isInspectedMemberStatic;
	Visibility inspectedMemberVisibility;
	boolean isInspectedMemberModifiable;
	String signature;
	Class<?> type;

	public CheckThat(String className, ClassType classType) {
		try {
			clazz = Class.forName(className);
			inspectedMemberVisibility = Visibility.getVisibility(clazz.getModifiers());
			isInspectedMemberModifiable = !Modifier.isFinal(clazz.getModifiers());
		} catch (Exception e) {
			fail(() -> String.format("A %s osztály nem létezik", className));
		}

		if (classType == ClassType.AN_INTERFACE) {
			assertTrue(clazz.isInterface(), () -> String.format("A %s nem interfész", className));
		}

		if (classType == ClassType.AN_ENUM) {
			assertTrue(clazz.isEnum(), () -> String.format("A %s nem felsorolási típus", className));

			for (var enumConstant : clazz.getEnumConstants()) {
				var enumConstantName = ((Enum<?>) enumConstant).name();
				assertTrue(enumConstantName.matches("[A-Z0-9_]+"),
					() -> String.format("A %s felsorolási típus '%s' eleme nem csupa nagybetűs", className, enumConstantName));
			}
		}

		this.className = className;
		this.classType = classType;
	}

	public static CheckThat theClass(String name) throws Exception {
		return new CheckThat(name, ClassType.A_CLASS);
	}

	public static CheckThat theInterface(String name) throws Exception {
		return new CheckThat(name, ClassType.AN_INTERFACE);
	}

	public static CheckThat theEnum(String name) throws Exception {
		return new CheckThat(name, ClassType.AN_ENUM);
	}

	private static String simpleParamText(Class<?>... expectedParams) {
		return Arrays.stream(expectedParams).map(Class::getSimpleName).collect(Collectors.joining(","));
	}

	private static String methodSignature(String methodName, Class<?>... expectedParams) {
		return String.format("%s(%s)", methodName, simpleParamText(expectedParams));
	}

	public CheckThat hasConstructorWithParams(Class<?>... expectedParams) throws Exception {
		String errMsg = String.format("A %s osztály nem rendelkezik (%s) paraméterezésű konstruktorral", className, simpleParamText(expectedParams));
		try {
			Constructor<?> constructor = clazz.getDeclaredConstructor(expectedParams);
			assertNotNull(constructor, errMsg);

			inspectedMember = InspectedMember.METHOD;
			inspectedMemberVisibility = Visibility.getVisibility(constructor.getModifiers());
		} catch (NoSuchMethodException e) {
			fail(errMsg);
		}
		return this;
	}

	public CheckThat hasMethodWithNoParams(String name) throws Exception {
		return hasMethodWithParams(name, new Class[0]);
	}

	public CheckThat hasMethodWithParams(String name, Class<?>... expectedParams) throws Exception {
		signature = methodSignature(name, expectedParams);
		try {
			Method method = clazz.getDeclaredMethod(name, expectedParams);

			type = method.getReturnType();
			inspectedMember = InspectedMember.METHOD;
			isInspectedMemberStatic = Modifier.isStatic(method.getModifiers());
			inspectedMemberVisibility = Visibility.getVisibility(method.getModifiers());
			isInspectedMemberModifiable = !Modifier.isFinal(method.getModifiers());
		} catch (NoSuchMethodException e) {
			fail(() -> String.format("Az osztály nem rendelkezik %s metódussal", signature));
		}

		return this;
	}

	public CheckThat hasMethodWithParams(String name, String... expectedParamTypeNames) throws Exception {
		Class<?>[] expectedParams = new Class[expectedParamTypeNames.length];
		for (int i = 0; i < expectedParamTypeNames.length; i++) {
			expectedParams[i] = getType(expectedParamTypeNames[i]);
		}
		return hasMethodWithParams(name, expectedParams);
	}

	public CheckThat hasFieldOfType(String name, String typeName) throws Exception {
		return hasFieldOfType(name, getType(typeName));
	}

	public CheckThat hasFieldOfType(String name, Class<?> type) throws Exception {
		signature = name;
		try {
			Field field = clazz.getDeclaredField(name);
			assertEquals(type, field.getType(), () -> String.format("A %s adattag típusa nem %s", signature, type.getSimpleName()));

			this.type = field.getType();
			inspectedMember = InspectedMember.FIELD;
			isInspectedMemberStatic = Modifier.isStatic(field.getModifiers());
			inspectedMemberVisibility = Visibility.getVisibility(field.getModifiers());
			isInspectedMemberModifiable = !Modifier.isFinal(field.getModifiers());
		} catch (NoSuchFieldException e) {
			fail(() -> String.format("Az osztály nem rendelkezik %s adattaggal", signature));
		}

		return this;
	}

	public CheckThat hasEnumElements(String... elems) {
		var enumConstants = Arrays.stream(clazz.getEnumConstants()).map(Object::toString).collect(Collectors.toSet());

		assertEquals(enumConstants.size(), elems.length,
			() -> String.format("A %s enum elemszáma nem megfelelő", className));

		for (String elem : elems) {
			assertTrue(enumConstants.contains(elem),
				() -> String.format("A %s enum nem tartalmazza ezt az elemet: %s", className, elem));
		}
		return this;
	}

	public CheckThat thatIs(Staticness statix) {
		assertEquals(statix, isInspectedMemberStatic ? Staticness.STATIC : Staticness.NOT_STATIC);
		return this;
	}

	public CheckThat thatIs(Visibility visibility) {
		assertEquals(visibility, inspectedMemberVisibility);
		return this;
	}

	public CheckThat thatIs(Modifiability modifiability) {
		assertEquals(modifiability == Modifiability.MODIFIABLE, isInspectedMemberModifiable);
		return this;
	}

	public CheckThat thatReturns(Class<?> expectedReturnType) {
		assertEquals(expectedReturnType, type);
		return this;
	}

	public CheckThat thatReturns(String expectedReturnTypeName) throws ClassNotFoundException {
		Class<?> expectedReturnType = getType(expectedReturnTypeName);
		return thatReturns(expectedReturnType);
	}

	public CheckThat thatHasParentClass(Class<?> expectedSuperType) {
		assertEquals(expectedSuperType, clazz.getSuperclass(),
			() -> String.format("A %s osztály szülője nem %s", className, expectedSuperType.getSimpleName()));
		return this;
	}

	public CheckThat thatHasParentClass(String expectedSuperTypeName) throws Exception {
		return thatHasParentClass(getType(expectedSuperTypeName));
	}

	private Class<?> getType(String typeName) throws ClassNotFoundException {
		try {
			return Class.forName(typeName);
		} catch (ClassNotFoundException e) {
			Map<String, Class<?>> primitivesAndVoid = Map.of(
				"void", void.class,
				"boolean", boolean.class,
				"byte", byte.class,
				"short", short.class,
				"char", char.class,
				"int", int.class,
				"long", long.class,
				"float", float.class,
				"double", double.class
				);

			if (primitivesAndVoid.containsKey(typeName))   return primitivesAndVoid.get(typeName);

			throw e;
		}
	}
}
