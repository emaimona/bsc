package school.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import school.schedule.Schedule;
import school.subject.SubjectType;

public class SchoolTest {
	Schedule[] schedules = new Schedule[4];
	Schedule scheduleInvalid;

	@BeforeEach
	public void beforeEach() {
		schedules[0] = new Schedule("schedule4.txt");
		schedules[1] = new Schedule("schedule5.txt");
		schedules[2] = new Schedule("schedule6.txt");
		schedules[3] = new Schedule("schedule7.txt");

		scheduleInvalid = new Schedule("scheduleInvalid.txt");
	}

	@ParameterizedTest
	@CsvSource({"4", "5", "6", "7"})
	public void classesPerDay(int year) {
		assertEquals(year, schedules[year-4].getClassesPerDay());
	}

	@ParameterizedTest
	@CsvSource({"4", "5", "6", "7"})
	public void suitable(int year) {
		assertEquals(true, schedules[year-4].isSuitableForYear(year));
	}

	@ParameterizedTest
	@CsvSource({"5", "6", "7"})
	public void notSuitable(int year) {
		assertEquals(false, schedules[year-4].isSuitableForYear(year-1));
	}

	@Test
	public void invalidName() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Schedule("abcdefg.txt");
		});
	}

	@Test
	public void shortContent() {
		assertThrows(IllegalStateException.class, () -> {
			new Schedule("scheduleShort.txt");
		});
	}

	@ParameterizedTest
	@CsvSource({"4,1,1,HUMANITY", "5,1,3,HUMANITY", "6,1,2,SCIENCE", "7,5,7,SCIENCE"})
	public void scheduledClassType(int year, int day, int slot, SubjectType subjectType) {
		assertEquals(subjectType, schedules[year-4].get(day, slot).getSubjectType());
	}
}

/* from inside solution folder:
javac -cp .;junit-platform-console-standalone-1.9.1.jar school\subject\Subject.java school\subject\SubjectType.java school\schedule\Schedule.java school\test\SchoolTest.java

java -jar junit-platform-console-standalone-1.9.1.jar -cp . -c school.test.SchoolTest */