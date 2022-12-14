import java.util.Arrays;
import java.util.LinkedList;

class IntListB {
    private LinkedList<Integer> data;
    //private int currentSize, maxSize;

    public IntListB() {
        data = new LinkedList<Integer>();
    }

    public IntListB (Integer[] array) {
        data = new LinkedList<Integer>();
        data.addAll(Arrays.asList(array));
    }

    public void add(int item) {
       data.add(item);
    }

    public LinkedList<Integer> getData() {
        return new LinkedList<Integer>(data);
    }

    public void concat(IntListB that) {
        data.addAll(that.data);
    }

    public void removeItemsGreaterThan(int limit) {
        data.removeIf(num -> (num > limit));
    }

    @Override
    public String toString() {
        if (data.size() < 0) {
            return "empty";
        } else {
            return data.toString();
        }
        
    }
}