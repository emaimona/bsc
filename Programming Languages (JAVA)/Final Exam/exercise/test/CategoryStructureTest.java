package exercise.test;

import exercise.test.util.CheckThat;
import org.junit.jupiter.api.Test;

import static exercise.test.util.CheckThat.Staticness.STATIC;
import static exercise.test.util.CheckThat.Visibility.PUBLIC;

public class CategoryStructureTest {

	@Test
	void structureCheckClass() throws Exception {
		CheckThat.theEnum("exercise.counter.Category")
			.thatIs(PUBLIC)
			.hasEnumElements("LETTER", "WHITESPACE", "OTHER");
	}

	@Test
	void structureCheckDetermineCategory() throws Exception {
		CheckThat.theClass("exercise.counter.Category")
			.hasMethodWithParams("determineCategory", char.class)
			.thatIs(STATIC)
			.thatIs(PUBLIC)
			.thatReturns("exercise.counter.Category");
	}
}
