package school.schedule;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import school.subject.Subject;

public class Schedule {
    public ArrayList<ArrayList<Subject>> schedule = new ArrayList<ArrayList<Subject>>();
    private int classesPerDay;

    public Schedule(String fileName) throws IllegalArgumentException{

        if (fileName.startsWith("schedule")) {
            String prefix = "school/schedule/";
            fillSchedule(prefix+fileName);
        } else {
            throw new IllegalArgumentException("File format is incorrect!");
        }     
    }

    private void fillSchedule(String fileName) throws IllegalStateException {
        int count = -1;
        
        File file = new File(fileName);
        try (Scanner sc = new Scanner(file)) {
            while (sc.hasNextLine() && count < 5) {
                String input = sc.nextLine();
                if (input.length() != 0) {
                    if (count == -1) {
                        this.classesPerDay = Integer.parseInt(input);
                    } else {
                        ArrayList<Subject> subj = new ArrayList<Subject>();
                        while (sc.hasNextLine() && input.length() != 0) {

                            addSubject(input, subj);
                            input = sc.nextLine();

                            if (!sc.hasNextLine()) {
                                addSubject(input, subj);
                            }
                        }

                        if (this.classesPerDay != subj.size()) {
                            throw new IllegalStateException("The file is incorrect!");
                        } else {
                            schedule.add(subj);
                        }
                    }
                    count++;
                }
            }

            if (count != 5) {
                throw new IllegalStateException("There are not enough classes!");
            }
        } catch (FileNotFoundException e) {
            System.out.println("File has not been found: " + fileName);
        }

    }

    public void addSubject(String subject, ArrayList<Subject> list) {
            if (Subject.CHEMISTRY == Subject.valueOf(subject)) {
                list.add(Subject.CHEMISTRY);
            } else if (Subject.HISTORY == Subject.valueOf(subject)) {
                list.add(Subject.HISTORY);
            } if (Subject.PHYSICS == Subject.valueOf(subject)) {
                list.add(Subject.PHYSICS);
            } if (Subject.LITERATURE == Subject.valueOf(subject)) {
                list.add(Subject.LITERATURE);
            }
    }

    public int getClassesPerDay() {
        return this.classesPerDay;
    }

    public String get(int dayN, int classN) {
        if ( (dayN > 5 || dayN < 1) || (classN > this.getClassesPerDay() || classN < 0)) {
            throw new IllegalArgumentException("Arguments are wrong!");
        }

        return this.schedule.get(dayN -1).get(classN - 1).toString();
    }


    public Boolean isSuitableForYear(int grade) {

        for (Subject e : Subject.values()) {
            if (e.getStartingYear() > grade) {
                return false;
            }
        }
        return true;
    }    
}
