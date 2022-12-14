import java.util.ArrayList;

class MainTask2 {
    public static ArrayList<String> getStrSameBeginningAndEnding(ArrayList<String> list) {
        ArrayList<String> result = new ArrayList<>();
        for (String element:list) {
            int len = element.length();
            if (len > 0 && element.charAt(0) == element.charAt(len -1)) {
                result.add(element);
            }
        } return result;
    }

    public static void removeStrDifferBeginningAndEnding(ArrayList<String> list) {
        list.removeIf(element -> (element.length() <= 0 || element.charAt(0) != element.charAt(element.length() -1)));
    }

    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("java");
        list.add("python");
        list.add("scala");
        list.add("");
        list.add("add____hgffds");
        list.add("ada");

        System.out.println("The original list: "+list);
        System.out.println("Same begin and end: "+getStrSameBeginningAndEnding(list));
        removeStrDifferBeginningAndEnding(list);
        System.out.println(list);

    }
}