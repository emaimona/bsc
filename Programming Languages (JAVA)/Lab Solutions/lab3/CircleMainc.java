
class Circle {
    private double x = 0;
    private double y = 0;
    private double radius = 1;

    public double getX() { return x; } //read
    public double getY() { return y; }
    public double getRadius() { return radius; }

    public Circle(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        if (radius <= 0) {
            throw new IllegalArgumentException("Circle setRadius(): radius should not be zero or negative");
        }
        this.radius = radius;
    }

    public Circle() {
        this.x = 2;
        this.y = 3;
        this.radius = 4;
    }

    public double getArea() {
        return Math.PI*radius*radius;
    }
}

class CircleMainc {
    public static void main(String[] args) {
        Circle c = new Circle(5,2,10);
        System.out.println("The area of the circle is: "+ c.getArea());

        Circle c2 = new Circle(); 
        System.out.println("The area of the circle is: "+ c2.getArea());

    }
}