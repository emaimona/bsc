package circle;
import circle.utils.Point;

class CircleMain {
    public static void main(String[] args) {
        Circle c = new Circle(3, 5, 10);
        System.out.println("The area is: "+ c.getArea());

        Point center = c.getCenter(); //3, 5
        System.out.println("center x = "+ center.getX() + "center y = " + center.getY());
    }
}