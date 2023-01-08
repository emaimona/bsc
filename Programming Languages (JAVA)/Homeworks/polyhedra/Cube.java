package lab11.polyhedra;

import lab11.polyhedra.Prism;
public class Cube extends Prism {
    public int h;

    public Cube(int h) {
        this.h = h;
    }

    @Override
    public int baseArea() {
        return h;
    }

    @Override
    public int volume() {
        return h;
    }

    @Override
    public String toString() {
        return String.format("Cube : (h=%d)", h);
    }
}
