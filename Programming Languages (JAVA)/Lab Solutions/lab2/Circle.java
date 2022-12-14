class Circle {
    double x,y; //origin
    double radius;

    void enlarge(double factor) {
        radius *= factor;
    }

    double getArea() {
        return Math.PI*radius*radius;
    }

    //add more methods

}