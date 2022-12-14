package exercise;

import exercise.PrettyCounter;
import exercise.counter.Counter;
import exercise.counter.Category;

public class Main {
    public static void main(String[] args) {
        PrettyCounter pretty = new PrettyCounter(args[0], 30);
        System.out.println(pretty.format(Category.OTHER));
        //System.out.println(pretty.toString());
    }
}