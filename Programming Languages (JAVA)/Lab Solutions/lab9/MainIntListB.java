import java.util.Arrays;
import java.util.LinkedList;

class MainIntListB {
    public static void main(String[] args) {
        try {
            IntListB list = new IntListB();
            list.add(3);
            list.add(5);
            //list.add(9); 
            System.out.println("first list: "+ list);

            IntListB list2 = new IntListB(new Integer[] {1,2,3,5}); 
            System.out.println("second list: "+ list2);
            list2.concat(list);
            System.out.println("second list after concat: "+ list2);
            list2.removeItemsGreaterThan(9);
            System.out.println("second list after removing some elements: "+ list2);
        } catch(IllegalStateException e) {
            System.out.println("Error");
        }
    }
}