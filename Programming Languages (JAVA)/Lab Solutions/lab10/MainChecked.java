
class MainChecked {
    public static void main(String[] args) throws AlreadyContainedException {
        CheckedSet<Car> set = new CheckedSet<>();
        set.add(new Car("BMW"));
        set.add(new Car("KIA"));
        System.out.println(set.toString());
        set.add(new Car("KIA"));  //it does not raise an exception, because we are adding a new Car

        CheckedSet<String> set2 = new CheckedSet<>();
        set2.add("David");
        set2.add("sara");
        //set2.add("sara");
        String sara = new String("sara");
        //set2.add(sara);
        System.out.println(set2.toString());
    }
}