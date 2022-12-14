package exercise.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ParameterContext;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.converter.ArgumentConversionException;
import org.junit.jupiter.params.converter.ArgumentConverter;
import org.junit.jupiter.params.converter.ConvertWith;
import org.junit.jupiter.params.provider.CsvSource;

import exercise.counter.Category;
import exercise.counter.Counter;

public class CounterTest {

    @Test
    void testConstructorEmptyInput() {
        assertDoesNotThrow(() -> new Counter(""));
    }

    @Test
    void testLeakingOfInnerState() {
        Counter counter = new Counter("abc123");
        List<Category> original = new ArrayList<>(counter.getCategories());

        try {
            counter.getCategories().remove(0);
        } catch (UnsupportedOperationException ignored) {
            // note: some lists don't support the remove operation
        }

        assertEquals(original, counter.getCategories(),
            "The method getCategories() should not leak the internal state of the object");
    }

    @ParameterizedTest
    @CsvSource({
        "a,    'LETTER'",
        "' ',  'WHITESPACE'",
        "0,    'OTHER'",
        "a 0,  'LETTER, WHITESPACE, OTHER'",
        "abc,  'LETTER, LETTER, LETTER'",
        "a0bc, 'LETTER, OTHER, LETTER, LETTER'"
    })
    void testGetCategories(String input, @ConvertWith(ToCategoryList.class) ArrayList<Category> expected) {
        assertEquals(expected, new Counter(input).getCategories());
    }

    @ParameterizedTest
    @CsvSource({
        "a,    LETTER, 1",
        "' ',  WHITESPACE, 1",
        "!,    OTHER, 1",
        "a !,  LETTER, 1",
        "a !,  WHITESPACE, 1",
        "a !,  OTHER, 1",
        "abc,  LETTER, 3",
        "a!bc, LETTER, 3",
        "a!bc, OTHER, 1"
    })
    void testGetCount(String input, Category category, int expected) {
        assertEquals(expected, new Counter(input).getCount(category));
    }

    @ParameterizedTest
    @CsvSource({
        "'a0a a0','WHITESPACE: 1|OTHER: 2|LETTER: 3'",
        "'a0aa0','OTHER: 2|LETTER: 3'",
        "'aa a','WHITESPACE: 1|LETTER: 3'",
        "'',''"
    })
    void testToString(String input, String output) {
        String actual = new Counter(input).toString();

        String[] expectedLines = output.split("\\|");
        String[] actualLines = actual
                // note: this is just whitespace cleanup
                .replaceAll("[\r\n]+", "\n")
                .split("\n");

        Arrays.sort(expectedLines);
        Arrays.sort(actualLines);
        assertArrayEquals(expectedLines, actualLines);
    }

    // Note: ignore the details of this conversion
    static class ToCategoryList implements ArgumentConverter {
        @Override
        public Object convert(Object arg, ParameterContext ctx) throws ArgumentConversionException {
            return Arrays.stream(((String)arg).split(", ")).map(Category::valueOf).collect(Collectors.toList());
        }
    }
}
