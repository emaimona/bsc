package circle;
import java.io.*;

import circle.utils.Point;

public class Circle {
    private double x = 0;
    private double y = 0;
    private double radius = 1;

    public Circle(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        if (radius <= 0) {
            throw new IllegalArgumentException("Circle setRadius(): radius is negative");
        }
        this.radius = radius;
    }

    public double getX() { return x; }
    public double getY() { return y; }
    public double getRadius() { return radius; }

    public double getArea(){
        return Math.PI*radius*radius;
    }

    public void enlarge(double f) {
        radius *= f;
    }

   public static Circle readFromFile(String filename) throws FileNotFoundException, IOException{ //factory method
        File input = new File(filename);
        BufferedReader bf = new BufferedReader(new FileReader(input));
        Double x = Double.parseDouble(bf.readLine());
        Double y = Double.parseDouble(bf.readLine());
        Double radius = Double.parseDouble(bf.readLine());

        bf.close();

        return new Circle(x,y,radius);
   }

   public void saveToFile(String filename) throws FileNotFoundException{
        File output = new File(filename);
        try (PrintWriter pw = new PrintWriter(output)) {
            pw.println(x);
            pw.println(y);
            pw.println(radius);
        }
   }
   
   public String toString() {
        return "(" + x + "," + y + "), r = " + radius;
    }

}