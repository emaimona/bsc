package Final_Practical_exam.exercise.counter;
import java.util.ArrayList;

public class Counter {
    ArrayList<Category> categories = new ArrayList<>();
    ArrayList<Category> getCategories() { return new ArrayList<>(categories); }
    public int getCount(Category cat) { 
        int count = 0;
        for (Category c: categories) {
            if (c == cat) count++;
        }
        return count; 
    }
    protected String format(Category category) {
        return category + ": "+ getCount(category);
    }

    public Counter(String input) {
        for (char c:input.toCharArray()) {
            categories.add(Category.determineCategory(c));
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Category category : Category.values()) {
            if (getCount(category) > 0) {
                sb.append(format(category)).append(System.lineSeparator());
            }
        }
        return sb.toString();
    }

}