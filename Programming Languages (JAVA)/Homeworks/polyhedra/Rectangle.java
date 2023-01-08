package lab11.polyhedra;

public class Rectangle implements Shape <Integer> {
    private int width, length;

    public Rectangle(int width, int length) {
        this.width = width;
        this.length = length;
    }

    public Integer getPerimeter() {
        return this.width * 2 + this.length * 2; 
    }

    public Integer getArea() {
        return this.width * this.length;
    }
    
}
