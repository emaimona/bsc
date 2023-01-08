package lab11.polyhedra;

//import lab11.polyhedra.Shape;

public class Square implements Shape<Integer>{
    private int side;

    public Square(int side) {
        this.side = side;
    }

    public Integer getPerimeter() {
        return this.side * 4;
    }

    public Integer getArea() {
        return this.side * this.side;
    }
}
