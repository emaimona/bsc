package exercise.test;

import exercise.PrettyCounter;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;


public class PrettyCounterTest {

	@Test
	void testConstructorEmptyInput() {
		assertThrows(IllegalArgumentException.class, () -> new PrettyCounter("", 42));
	}

	@ParameterizedTest
	@CsvSource({
		"'a0a a0', 3, '# WHITESPACE: 1\n## OTHER: 2\n### LETTER: 3'",
		"'aaa0',   2, '# OTHER: 1\n## LETTER: 3'",
		"'aaaaa0', 2, '# OTHER: 1\n## LETTER: 5'",
	})
	void testToString(String input, int maxWidth, String expected) {
		String actual = new PrettyCounter(input, maxWidth).toString();

		String[] expectedLines = expected.split("\n");
		String[] actualLines = actual
				// note: this is just whitespace cleanup
				.replaceAll("[\r\n]+", "\n")
				.split("\n");

		Arrays.sort(expectedLines);
		Arrays.sort(actualLines);
		assertArrayEquals(expectedLines, actualLines);
	}
}
