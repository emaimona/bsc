
public class MainMultiSet {
    public static void main(String[] args) {
        MultiSet set1 = new MultiSet();
        set1.put("Ahmed");
        set1.put("Java");
        set1.put("Java");
        set1.put("Java");
        set1.put("Javascript");
        set1.put("python");
        set1.put("python");
        System.out.println("set1 = "+ set1.getData());

        MultiSet set2 = new MultiSet();
        set2.put("Ahmed");
        set2.put("Javascript");
        set2.put("python");
        set2.put("Ali");
        System.out.println("set2 = "+ set2.getData());

        MultiSet intersectionResult = set1.intersect(set2);
        System.out.println("The intersection result: " + intersectionResult.getData());



    }
}