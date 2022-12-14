package exercise.test;

import exercise.test.util.CheckThat;
import org.junit.jupiter.api.Test;

import static exercise.test.util.CheckThat.Staticness.NOT_STATIC;
import static exercise.test.util.CheckThat.Visibility.PRIVATE;
import static exercise.test.util.CheckThat.Visibility.PROTECTED;
import static exercise.test.util.CheckThat.Visibility.PUBLIC;

public class PrettyCounterStructureTest {

	@Test
	void structureCheckClass() throws Exception {
		CheckThat.theClass("exercise.PrettyCounter")
			.thatIs(PUBLIC)
			.thatHasParentClass("exercise.counter.Counter");
	}

	@Test
	void structureCheckMaxWidthField() throws Exception {
		CheckThat.theClass("exercise.PrettyCounter")
			.hasFieldOfType("maxWidth", int.class)
			.thatIs(NOT_STATIC)
			.thatIs(PRIVATE);
	}

	@Test
	void structureCheckMaxCountField() throws Exception {
		CheckThat.theClass("exercise.PrettyCounter")
			.hasFieldOfType("maxCount", int.class)
			.thatIs(NOT_STATIC)
			.thatIs(PRIVATE);
	}

	@Test
	void structureCheckConstructor() throws Exception {
		CheckThat.theClass("exercise.PrettyCounter")
			.hasConstructorWithParams(String.class, int.class)
			.thatIs(PUBLIC);
	}

	@Test
	void structureCheckFormat() throws Exception {
		CheckThat.theClass("exercise.PrettyCounter")
			.hasMethodWithParams("format", "exercise.counter.Category")
			.thatIs(NOT_STATIC)
			.thatIs(PROTECTED);
	}
}
