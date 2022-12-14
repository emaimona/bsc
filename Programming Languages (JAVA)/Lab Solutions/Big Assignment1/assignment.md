
# Java first assignment

You will be implementing a simplified school simulation.
Make the code as good quality as you can.
Follow the Java conventions when it comes to styling/formatting your code (correct indentation, standard capitalization in names, etc.)
and other best practices (proper encapsulation, closing all opened files, etc.).

Create the `school.subject.SubjectType` enumeration type with the following values: `HUMANITY` and `SCIENCE`.

Create the `school.subject.Subject` enumeration type with the following values: `LITERATURE`, `HISTORY`, `PHYSICS`, and `CHEMISTRY`.
Its `subjectType` field stores the category of the subject (the first two are `HUMANITY`, the second two are `SCIENCE`),
and the `startingYear` field stores the grade where the subject is first taught (its value is 4, 5, 6, and 7 respectively).
Also create standard getter methods for the fields.

The constructor of the `school.schedule.Schedule` receives a file name.
If the file name doesn't start with the `schedule` character sequence, throw an `IllegalArgumentException`.
Otherwise, you may assume (without manually checking) that the file exists and its formatted as described below.
The constructor wil read in the subjects and store them appropriately.

- The first line contains a single number: how many classes there are daily.
    - There is school 5 days a week.
    - Each day has the same number of classes.
- The remaining lines each contain a single `Subject` in a text representation.
    - Monday's classes come first, then Tuesday's classes follow and so on.
    - Hint: you may use the `valueOf` method of enum types.
    - Some lines may be empty; ignore those.
- If there aren't enough lines to fill each day with classes, throw an `IllegalStateException`.

The `Schedule` class has three additional methods:

- `getClassesPerDay()`: self-explanatory.
- `get(dayN, classN)`: returns the `Subject` that is held at the specified time. The days and classes are counted from one, so for example the parameters to query Tuesday's first class are: `(2, 1)`.
- `isSuitableForYear(grade)`: returns whether the specified grade is at least as much as the `startingYear` value of each subject in the schedule.

Create the `school.test.SchoolTest` class to contain JUnit 5 tests for the application.

- Create a `beforeEach` method in this class (annotated with `@BeforeEach`) that fills the `schedules` array's four elements using the `scheduleX.txt` files where `X` is 4, 5, 6, and 7. The array elements' type is `Subject`.
    - The file named `scheduleX.txt` must be suitable for grade `X` and must contain `X` classes per day.
- Write test cases in the following methods. The test cases should be parameterized when necessary.
    - `classesPerDay`: all 4 loaded schedules' `getClassesPerDay` method returns the correct value
    - `scheduledClassType`: for all 4 loaded schedules validate that at least one subject (on a given day at a given time) has the correct category (`SubjectType`)
        - For example, you can check whether the seventh-graders' subject on Friday in the seventh time slot has the `SCIENCE` category.
    - `suitable`: all 4 loaded schedules return `true` when `isSuitableForYear` is called with the appropriate grade.
    - `notSuitable`: the last 3 schedules (the ones for fifth-graders, sixth-graders and seventh-graders) return `false` when `isSuitableForYear` is called with the grade that is one less than the grade the schedule is for (e.g. the fifth-graders' schedule is not suitable for fourth-graders).
    - `invalidName`: calling `Schedule`'s constructor with the `abcdefg.txt` file name causes an `IllegalArgumentException` to occur.
    - `shortContent`: calling `Schedule`'s constructor with the `scheduleShort.txt` file name causes an `IllegalStateException` to occur, where the `scheduleShort.txt` is a file with a single line, whose content is just the character `1`.

As you will be executing your program using JUnit, you dont need to write a `main` method.

compile and run commands:
------------------------
from inside solution folder:
javac -cp .;junit-platform-console-standalone-1.9.1.jar school\subject\Subject.java 
school\subject\SubjectType.java school\schedule\Schedule.java school\test\SchoolTest.java

javac -cp .;junit-platform-console-standalone-1.9.1.jar school\test\schoolTest.java

java -jar junit-platform-console-standalone-1.9.1.jar -cp . -c school.test.SchoolTest
