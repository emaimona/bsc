package exercise.test;

import org.junit.platform.suite.api.*;

@Suite
@SelectClasses({
	CategoryStructureTest.class,
	CategoryTest.class

	, CounterStructureTest.class
	, CounterTest.class

	 , PrettyCounterStructureTest.class
	 , PrettyCounterTest.class
})
public class ExerciseTestSuite { }
