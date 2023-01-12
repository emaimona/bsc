package test.flying;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import java.util.Objects;

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
import travel.flying.Plane;

public class PlaneTest {
    Plane p1 = Plane.make("Mydia,12,250");
    Plane p2 = Plane.make("Mydia,12,250");
    Plane p3 = Plane.make("AirBus,11,140");

    @Test
    void testMake() {
        Plane plane = Plane.make("Fry,12,140");
        assertEquals("Fry,12,140", plane.toString());
    }

    @Test 
    void testEquals() {
        assertTrue(p1.equals(p2));
        assertEquals(p1, p2);
        assertEquals(p1.toString(), p2.toString());
        assertNotEquals(p1, p3);
    }

    @Test
    void testHashCode() {
        assertEquals(p1.hashCode(), p2.hashCode());
        assertNotEquals(p1, p3);
        assertNotEquals(p2, p3);
    }

    @Test
    void testGetPriceThrows() {
        assertThrows(IllegalArgumentException.class, () -> {
            p1.getPrice(2.0);
        });
        assertThrows(IllegalArgumentException.class, () -> {
            p1.getPrice(-.9);
        });
    }

    @ParameterizedTest
    @CsvSource({
        "'BERLIN-2020.12.30.14.30', 16",
        "'ROME-2020.12.30.22.30', 00",
        "'AMSTERDAM-2020.12.30.23.30', 01",
        "'PARIS-2020.12.30.01.30', 03",
        "'HELSINKI-2020.12.30.14.30', 17"
    })
    void testEstimatedArrivalTimeContraints(String input, String expected) {
        Destination dest = Destination.valueOf(input.split("-")[0]);
        String s = input.split("-")[1];
        String p[] = s.split("\\.");
        DayAndTime dayTime = new DayAndTime(Integer.parseInt(p[0]), Integer.parseInt(p[1]), Integer.parseInt(p[2]), Integer.parseInt(p[3]), Integer.parseInt(p[4]));
        assertEquals(Integer.parseInt(expected), p1.estimatedArrivalTime(dest, dayTime));
    }

    @Test
    void testEstimatedArrivalTime() {
        String info = p1.getFlightDayAndTime();
        String p[] = info.split("\\.");
        int year = Integer.parseInt(p[0]);
        int month = Integer.parseInt(p[1]);
        String dtime[] = p[2].split(" at ");
        int day = Integer.parseInt(dtime[0]);
        int hour = Integer.parseInt(dtime[1].split(":")[0]);
        int minute = Integer.parseInt(dtime[1].split(":")[1]);

        DayAndTime dayTime = new DayAndTime(year, month, day, hour, minute);
        assertEquals(6, p1.estimatedArrivalTime(p1.getDestinationCity(), dayTime));
    }

}
