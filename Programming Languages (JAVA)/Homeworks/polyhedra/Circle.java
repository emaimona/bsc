package lab11.polyhedra;

public class Circle implements Shape<Double> {
    public double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public Double getPerimeter() {
        return 2 * this.radius * Math.PI;
    }
    public Double getArea() {
        return 2 * this.radius * this.radius * Math.PI;
    }
}