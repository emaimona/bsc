package test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

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

public class DayAndTimeTest {

    @Test
	void testConstructorEmptyInput() {
        DayAndTime dayTime = new DayAndTime();
        assertEquals(22, dayTime.getDay());
		assertEquals("2021.12.22 at 04:30", dayTime.toString());
	}

    @Test
    void testConstructor() {
        DayAndTime dayTime = new DayAndTime(2022,01,13,12,30);
        assertEquals("2022.01.13 at 12:30", dayTime.toString());
    }

    @Test
    void testOutputParameters() {
        DayAndTime dayTime = new DayAndTime(2000,5,7,2,5);
        assertEquals("02:05", dayTime.getTime());
        assertEquals(2000, dayTime.getYear());
        assertEquals(5, dayTime.getMonth());
        assertEquals(7, dayTime.getDay());
        assertEquals(2, dayTime.getHour());
        assertEquals(5, dayTime.getMinute());
        assertEquals("2000.05.07 at 02:05", dayTime.toString());
    }

    @Test
    void testOutputParametersEmptyConstructor() {
        DayAndTime dayTime = new DayAndTime();
        assertEquals("04:30", dayTime.getTime());
        assertEquals(2021, dayTime.getYear());
        assertEquals(12, dayTime.getMonth());
        assertEquals(22, dayTime.getDay());
        assertEquals(4, dayTime.getHour());
        assertEquals(30, dayTime.getMinute());
    }
}