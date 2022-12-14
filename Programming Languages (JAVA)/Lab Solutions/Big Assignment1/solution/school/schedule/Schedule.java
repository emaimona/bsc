package school.schedule;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import school.subject.Subject;

public class Schedule {
	Subject[][] classes = new Subject[5][];

	public Schedule(String filename) {
		if (!filename.startsWith("schedule")) {
			throw new IllegalArgumentException();
		}

		try (var br = new BufferedReader(new FileReader(filename))) {
			int classesPerDay = Integer.parseInt(br.readLine());

			for (int day = 0; day < 5; day++) {
				classes[day] = new Subject[classesPerDay];
				for (int cl = 0; cl < classesPerDay; cl++) {
					String line = br.readLine();
					if (line == null) {
						throw new IllegalStateException();
					}
					if (line.equals("")) {
						--cl;
						continue;
					}

					classes[day][cl] = Subject.valueOf(line);
				}
			}
		} catch (IOException e) {
			// considered impossible
		}
	}

	public int getClassesPerDay() {
		return classes[0].length;
	}

	public Subject get(int day, int cl) {
		return classes[day-1][cl-1];
	}

	public boolean isSuitableForYear(int year) {
		for (var day : classes) {
			for (var cl : day) {
				if (cl.getStartingYear() > year) {
					return false;
				}
			}
		}
		return true;
	}
}
