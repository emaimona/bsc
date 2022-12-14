package Final_Practical_exam.exercise;

import Final_Practical_exam.exercise.counter.Category;
import Final_Practical_exam.exercise.counter.Counter;

public class PrettyCounter extends Counter {
    private int maxWidth;
    private int maxCount;

    public PrettyCounter(String input, int maxWidth) {
        super(input);
        if (input.isEmpty()) throw new IllegalArgumentException();
        this.maxWidth = maxWidth;

        maxCount = 0;
        for (Category category : Category.values()) {
            maxCount = Math.max(maxCount, getCount(category));
        }
    }

    @Override
    protected String format(Category category) {
        StringBuilder builder = new StringBuilder();
        int count = (maxWidth * getCount(category) + maxCount - 1) / maxCount;
        for (int i = 0; i < count; ++i) builder.append('#');
        return builder.append(' ').append(super.format(category)).toString();
    }
}