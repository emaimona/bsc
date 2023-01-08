import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class lab9H {

    public static String getStatistics(String string) {
        HashMap<Character, Integer> collection = new HashMap<>();
        char[] arr = string.toCharArray();

        for (char e : arr) {
            if (collection.containsKey(e)) {
                int count = collection.get(e);
                collection.put(e, count+1);
            } else {
                collection.put(e,1);
            }
        }
        
       StringBuilder result = new StringBuilder();
       for (char e: arr) {
            result.append(e+"("+ collection.get(e)+")");
       }
       return result.toString();
    }

    public static void removeEvenString(ArrayList<String> list) {

        for (String s: list) {
            int len = s.length();
            if (len % 2 == 0) {
                list.remove(s);
            }
        }
        System.out.println(list.toString());

    }

    public static void main(String args[]) {
        String name = "HelloWorld";
        ArrayList<String> list = new ArrayList<>(List.of("Jorge", "Mark", "Arila"));

        System.out.println( getStatistics(name)+"\n");

        removeEvenString(list);
        System.out.println(list.toString());
    }
}
