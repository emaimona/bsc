class Point {
    double x, y; //fields

    void move(double dx, double dy) { //
        x += dx; 
        y += dy;
    }
    void mirror(double cx, double cy) { //reflection point
        x = 2*cx - x;
        y = 2*cy - y;
    }
    
    void mirror(Point p) {
        x = 2*p.x - x;
        y = 2*p.y - y;
    }

    double distance(Point p) {
        double dx = x - p.x;
        double dy = y - p.y;
        return Math.sqrt(dx*dx+ dy*dy); //
    }
}