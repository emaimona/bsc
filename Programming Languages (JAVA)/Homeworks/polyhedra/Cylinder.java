package lab11.polyhedra;

import lab11.polyhedra.Prism;

public class Cylinder extends Prism {
    public int h;
    public int r;
    
    public Cylinder(int h, int r) {
        this.h = h;
        this.r = r;
    }

    @Override
    public int baseArea() {
        return r;
    }

    @Override
    public int volume() {
        return h;
    }

    @Override 
    public String toString() {
        return String.format("Cylinder : (h=%d , r=%d)", h, r);
    }
}