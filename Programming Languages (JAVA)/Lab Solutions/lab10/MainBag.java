import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class MainBag {
    public static void main(String[] args) throws NotInBagException {
        Bag<String> bag = new Bag<>();
        bag.add("Ahmed");
        bag.add("Aron");
        bag.add("Sara");
        bag.add("Sara");
        bag.add("David");
        bag.add("Tamas");
        bag.add("Aron");
        System.out.println(bag);
        System.out.println("Bag count of: " +bag.countOf("Aron"));

        File input = new File(args[0]);
        Bag<String> statistics = new Bag<>();

        try (Scanner sc = new Scanner(input)) {
            while (sc.hasNextLine()) {
                statistics.add(sc.nextLine());
            }
        } catch (FileNotFoundException e) {
            System.out.println("Unable to access the file " + args[0]);
        }
        System.out.println("Word statistics: " + statistics);
        statistics.remove("protected");
        System.out.println("Word statistics after removing: " + statistics);
    }
}