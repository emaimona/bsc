package school.test;
//package test;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.fail;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.*;

// import org.junit.Test;
// import org.junit.Before;
// import org.junit.jupiter.api.BeforeEach;
// import static org.junit.Assert.*;
// import static org.junit.Assert.assertEquals;

import school.schedule.Schedule;
import school.subject.Subject;
import school.subject.SubjectType;

public class SchoolTest {
    static Schedule sch4;
    static Schedule sch5;
    static Schedule sch6;
    static Schedule sch7;

    Schedule scshort;
    ArrayList<Schedule> schlist;
    
    @BeforeEach
    public void beforeEach() {
        sch4 = new Schedule("schedule4.txt");
        sch5 = new Schedule("schedule5.txt");
        sch6 = new Schedule("schedule6.txt");
        sch7 = new Schedule("schedule7.txt");
    }

    @Test
    public void classesPerDay() {
        assertEquals(4, sch4.getClassesPerDay());
        assertEquals(5, sch5.getClassesPerDay());
        assertEquals(6, sch6.getClassesPerDay());
        assertEquals(7, sch7.getClassesPerDay());
    }

    private static Stream<Schedule> singleArguments() {
        return Stream.of(sch4, sch5, sch6, sch7);
    }

    @ParameterizedTest
    @MethodSource("singleArguments")
    public void scheduledClassTypeAll(Schedule sch) {
        Boolean value = false;
        for (ArrayList<Subject> subj : sch.schedule) {
            for (Subject subject: subj) {
                if (subject.getSubjectType() == SubjectType.HUMANITY || subject.getSubjectType() == SubjectType.SCIENCE) {
                    value = true;
                } else {
                    value = false;
                    fail();
                }
            }
        }
        assertEquals(true, value);
    }


    @Test 
    public void scheduledClassTypeScience(){
        // Monday  4 => chemistry 
        // Indexes start at 0

        SubjectType sbt4 = sch4.schedule.get(4).get(3).getSubjectType();
        SubjectType sbt5 = sch5.schedule.get(4).get(4).getSubjectType();
        SubjectType sbt6 = sch6.schedule.get(4).get(5).getSubjectType();
        SubjectType sbt7 = sch7.schedule.get(4).get(6).getSubjectType();
        assertTrue(sbt4 == SubjectType.SCIENCE);
        assertTrue(sbt5 == SubjectType.SCIENCE);
        assertTrue(sbt6 == SubjectType.SCIENCE);
        assertTrue(sbt7 == SubjectType.SCIENCE);
    }


    @Test 
    public void suitable() {
        assertTrue(sch4.isSuitableForYear(7));
        assertTrue(sch5.isSuitableForYear(7));
        assertTrue(sch6.isSuitableForYear(7));
        assertTrue(sch7.isSuitableForYear(7));
    }

    @Test 
    public void notSuitable() {
        assertFalse(sch4.isSuitableForYear(3));
        assertFalse(sch5.isSuitableForYear(4));
        assertFalse(sch6.isSuitableForYear(5));
        assertFalse(sch7.isSuitableForYear(6));

    }

    @Test
    public void invalidName() {
        // String prefix = "school/schedule/" is automatically added on the class
        assertThrows(IllegalArgumentException.class, () -> {
            sch4 = new Schedule("abcdefg.txt");
        });
    
    }

    @Test
    public void shortContent() {
          // String prefix = "school/schedule/" is automatically added on the class
        assertThrows(IllegalStateException.class,()-> {
            scshort = new Schedule("scheduleShort.txt");
        });
        
    }
}
