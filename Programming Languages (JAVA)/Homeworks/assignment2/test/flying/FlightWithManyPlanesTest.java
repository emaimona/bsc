package test.flying;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import java.util.Objects;
import java.util.ArrayList;
import java.util.List;
import java.io.IOException;
import java.io.File;
import java.io.FileReader;
import java.beans.Transient;
import java.io.BufferedReader;


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
import travel.flying.FlightWithManyPlanes;


public class FlightWithManyPlanesTest {
    ArrayList<Plane> planes = new ArrayList<Plane>(List.of(
        Plane.make("Airbus,12,150"),
        Plane.make("Tag,13,145"),
        Plane.make("Qatar,17,200")
    ));

    FlightWithManyPlanes fmp = new FlightWithManyPlanes(
            "Dream", 
            Destination.ROME, 
            15, 
            new DayAndTime(), 
            planes);

    @Test 
    void testConstructThrows() {
        assertThrows(IllegalArgumentException.class, () -> {
            fmp = new FlightWithManyPlanes("Test", Destination.ROME, 10, new DayAndTime(), planes);
        });
    }

    @ParameterizedTest
    @CsvSource({
        "LOVE, PARIS, 45, love_ticket.txt",
        "JOB, BERLIN, 15, job_ticket.txt",
        "BONUS, ROME, 100, bonus_ticket.txt",
    })
    void testSave(String inp1, String inp2, String inp3, String filename) {
        fmp = new FlightWithManyPlanes(
            inp1,
            Destination.valueOf(inp2),
            Integer.parseInt(inp3),
            new DayAndTime(),
            planes
            );

        assertDoesNotThrow(() -> {
            fmp.save(filename);
            BufferedReader br = new BufferedReader(new FileReader(filename));
            assertEquals(inp1, br.readLine());
            assertEquals(inp2, br.readLine());
            assertEquals(inp3, br.readLine());
            assertEquals((new DayAndTime()).toString(), br.readLine());
            for (Plane p: planes)
                assertEquals(p.toString(), br.readLine());
        });
    }

    @ParameterizedTest
    @CsvSource({
        "STUDY, ROME, 95, study_ticket.txt",
        "BALA, BERLIN, 50, bala_ticket.txt",
        "GIGA, AMSTERDAM, 80, giga_ticket.txt",
    })
    void testLoad(String inp1, String inp2, String inp3, String filename) {
        testSave(inp1, inp2, inp3, filename); // Creates a file

        // Insert Some Random values
        fmp = new FlightWithManyPlanes(
            "Default",
            Destination.HELSINKI,
           100,
            new DayAndTime(),
            new ArrayList<>()
            );

        assertDoesNotThrow(() -> {
            fmp.load(filename);
            assertEquals(inp1, fmp.getName());
            assertEquals(inp2, fmp.getDestinationCity().name());
            assertEquals(Integer.parseInt(inp3), fmp.getNumberOfTravellers());
            assertEquals(planes.size(), fmp.getPlanes().size());
            for (int i=0; i<planes.size(); i++) {
                assertEquals(planes.get(i), fmp.getPlanes().get(i));
            }
        });
    }
     

    @Test 
    void testGetCheapestRide() {
        assertEquals(planes.get(1), fmp.getCheapestRide(0.2));
    }

    @Test
    void testGetCheapestRideThrows() {
        assertThrows(IllegalArgumentException.class, () -> {
            fmp.getCheapestRide(1);
        });
        assertThrows(IllegalStateException.class, () -> {
            fmp.getPlanes().clear();
            fmp.getCheapestRide(0.2);
        });
    }
}
