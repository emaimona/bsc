package exercise.counter;

import java.util.ArrayList;
import java.util.*;
import java.lang.Object;

import exercise.counter.Category;

public class Counter {
    protected ArrayList<Category> categories = new ArrayList<Category>();

    public Counter(String input) {
    
        char[] chars = input.toCharArray();
        for (char ch: chars) {
            this.categories.add(Category.determineCategory(ch));
        }
    }

    public ArrayList<Category> getCategories() {
        return this.categories;
    }

    public int getCount(Category category) {
        int count = 0;

        for (Category cat: this.categories) {
            if (cat == category)
                count++;
        }

        return count;
    }

    protected String format (Category category) {
        return category.toString()+": "+getCount(category);
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();

        for(Category cat: categories) {
            if (getCount(cat)>0)
                str.append(format(cat)).append("\n");
        }

        return str.toString();
    }

}