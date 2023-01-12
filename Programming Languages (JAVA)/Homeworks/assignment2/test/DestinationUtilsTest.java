package test;


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

import travel.DestinationUtils;
import travel.Destination;
import travel.DayAndTime;

public class DestinationUtilsTest {

    @ParameterizedTest
    @CsvSource({
        "01:34, BERLIN",
        "01:45, ROME",
        "02:05, AMSTERDAM",
        "02:20, PARIS",
        "02:43, HELSINKI",
        "00:00, "
    })
    void testGetDestination(String input, String expected) {
        assertEquals(expected, DestinationUtils.getDestination(input));
    }

    @ParameterizedTest
    @CsvSource({
        "BERLIN, 01:34",
        "ROME, 01:45",
        "AMSTERDAM, 02:05",
        "PARIS, 02:20",
        "HELSINKI, 02:43",
    })
    void testGetDestinationDuration(String input, String expected) {
        Destination dest = Destination.valueOf(input);
        assertEquals(expected, DestinationUtils.getDestinationDuration(dest));
    }

    @ParameterizedTest
    @CsvSource({
        "BERLIN, 2",
        "ROME, 2",
        "AMSTERDAM, 2",
        "PARIS, 2",
        "HELSINKI, 3"
    })
    void testGetRoundedHours(String input, String expected) {
        Destination dest = Destination.valueOf(input);
        assertEquals(expected, DestinationUtils.getRoundedHours(dest));
    }
    
    
}
