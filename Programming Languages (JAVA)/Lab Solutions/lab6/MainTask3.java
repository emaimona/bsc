
import java.io.*;
import java.util.Scanner;

class MainTask3 {
    public static void main(String[] args) {
        System.out.print("Enter a sample to ind in the file:");
        String sample = System.console().readLine();

        File input = new File(args[0]);
        Scanner sc = null;

        try {
            sc = new Scanner(input);

            int counter = 0;
            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                if (line.contains(sample)) {
                    ++counter;
                }
            }
            System.out.println("counter = "+ counter);
            //sc.close(); //this is not good location
        } catch (FileNotFoundException e) {
            System.out.println("Unable to access the file " + args[0]);
        } finally {
            sc.close();
        }

    }
}