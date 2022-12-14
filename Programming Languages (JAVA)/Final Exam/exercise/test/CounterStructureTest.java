package exercise.test;

import exercise.test.util.CheckThat;
import org.junit.jupiter.api.Test;
import java.util.ArrayList;

import static exercise.test.util.CheckThat.Staticness.NOT_STATIC;
import static exercise.test.util.CheckThat.Visibility.PRIVATE;
import static exercise.test.util.CheckThat.Visibility.PROTECTED;
import static exercise.test.util.CheckThat.Visibility.PUBLIC;

public class CounterStructureTest {

	@Test
	void structureCheckClass() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
				.thatIs(PUBLIC);
	}

	@Test
	void structureCheckCategoriesField() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
			.hasFieldOfType("categories", ArrayList.class)
			.thatIs(NOT_STATIC)
			.thatIs(PRIVATE);
	}

	@Test
	void structureCheckConstructor() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
			.hasConstructorWithParams(String.class);
	}

	@Test
	void structureCheckGetCategories() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
			.hasMethodWithNoParams("getCategories")
			.thatIs(NOT_STATIC)
			.thatIs(PUBLIC)
			.thatReturns(ArrayList.class);
	}

	@Test
	void structureCheckGetCount() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
			.hasMethodWithParams("getCount", "exercise.counter.Category")
			.thatIs(NOT_STATIC)
			.thatIs(PUBLIC)
			.thatReturns(int.class);
	}

	@Test
	void structureCheckFormat() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
			.hasMethodWithParams("format", "exercise.counter.Category")
			.thatIs(NOT_STATIC)
			.thatIs(PROTECTED)
			.thatReturns(String.class);
	}

	@Test
	void structureCheckToString() throws Exception {
		CheckThat.theClass("exercise.counter.Counter")
			.hasMethodWithNoParams("toString")
			.thatIs(NOT_STATIC)
			.thatIs(PUBLIC)
			.thatReturns(String.class);
	}
}
