import java.util.HashMap;

class MultiSet {
                   //key, multiplicity
    private HashMap<String, Integer> data;

    public MultiSet() {
        data = new HashMap<String, Integer>();
    }

    public MultiSet(HashMap<String, Integer> initialData) {
        data = new HashMap<String, Integer>(initialData);
    }

    public HashMap<String, Integer> getData() {
        return new HashMap<String, Integer>(data);

    }

    public void put(String item) {
        if (data.containsKey(item)) {
            int mult = data.get(item) + 1;
            data.replace(item, mult);
        } else {
            data.put(item, 1); //this put() method of java Hashmap
        }
    }

    public MultiSet intersect(MultiSet other) {
        HashMap<String, Integer> resultData = new HashMap<>();
        for (String key: data.keySet()) {
            if (other.data.containsKey(key)) {
                resultData.put(key, Math.min(data.get(key), other.data.get(key)));
            }
        } return new MultiSet(resultData);
    }
}