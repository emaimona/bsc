package exercise;

import exercise.counter.Counter;
import exercise.counter.Category;
public class PrettyCounter extends Counter {
    private int maxWidth;
    private int maxCount;

    public PrettyCounter (String text, int maxWidth) throws IllegalArgumentException {
        super(text);
        if (text == "")
            throw new IllegalArgumentException("Text cannot be empty!");
        

        for(Category cat: super.categories) {
            if (getCount(cat)> this.maxCount)
                this.maxCount = getCount(cat);      
        }
    }

    @Override
    protected String format(Category category) {
        int count = getCount(category);
        count = maxWidth * count / maxCount;
        StringBuilder str = new StringBuilder();

        for (int i=0; i<count; i++)
            str.append("#");

        return str + " " + category.toString()+": "+getCount(category);
    }
}