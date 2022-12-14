package circle;
import java.io.*;

import circle.utils.Point;

class MainC {
    public static void main(String[] args) {
        Circle c = new Circle(4,3,11);
        System.out.println(c);

        c.enlarge(3);
        System.out.println(c);

        Circle c2 = null;

        try {
            c.saveToFile("copy1.txt");

            c2 = Circle.readFromFile("circledata.txt");
        } catch(FileNotFoundException e) {
            System.out.println("File not found");
        } catch(IOException e) {
            System.out.println("IO Error");
        }

        System.out.println("c2 circle"+c2);
    }
}