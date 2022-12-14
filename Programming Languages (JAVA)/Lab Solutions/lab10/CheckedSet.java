import java.util.HashSet;
import java.util.Set; 

public class CheckedSet<T> {
    private Set<T> set = new HashSet<>();

    public int size() {
        return set.size();
    }

    public void add(T element) throws AlreadyContainedException {
        if (contains(element)) {
            throw new AlreadyContainedException();
        }
        set.add(element);
    }

    public boolean contains(T element) {
        return set.contains(element);
    }

    @Override
    public String toString() {
        return set.toString();
    }
}