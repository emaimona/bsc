package exercise.test;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import exercise.counter.Category;

public class CategoryTest {

	@ParameterizedTest
	@CsvSource({
		"a,   LETTER",
		"A,   LETTER",
		"' ', WHITESPACE",
		"0,   OTHER",
		"?,   OTHER"
	})
	void testDetermineCategory(char input, Category output) {
		assertEquals(output, Category.determineCategory(input));
	}
}
