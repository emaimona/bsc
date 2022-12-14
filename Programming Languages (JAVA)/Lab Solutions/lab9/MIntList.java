
class MIntList {
    public static void main(String[] args) {

        try {
            IntList list = new IntList(2);
            list.add(2);
            list.add(3);
            //list.add(4);
            System.out.println("1st IntList: " + list);

            IntList list2 = new IntList(5);
            list2.add(2);
            list2.add(3);
            list2.add(4);
            System.out.println("2ed IntList before concat: " + list2);
            list2.concat(list);
            System.out.println("2ed IntList after concat: " + list2);
            list2.removeItemsGreaterThan(3);
            System.out.println("2ed IntList after removing: " + list2);
        } catch(IllegalStateException e) {
            System.out.println("Some error");
        }
        
    }
}