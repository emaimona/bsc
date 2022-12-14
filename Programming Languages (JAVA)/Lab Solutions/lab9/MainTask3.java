import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class MainTask3 {
    public static void minToFront(ArrayList<Integer> numbers) {
        if (numbers.isEmpty()) {
            throw new IllegalArgumentException();
        }
        //int min = Collections.min(numbers);
        Integer min = Collections.min(numbers);
        numbers.remove(min);
        numbers.add(0, min);
    }

    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.addAll(Arrays.asList(4,56,7,8,9,2,0));
        System.out.println(numbers);
        minToFront(numbers);
        System.out.println(numbers);

    }
}