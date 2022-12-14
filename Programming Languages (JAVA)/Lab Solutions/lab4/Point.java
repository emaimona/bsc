public class Point {
    private double x, y;
    int id; //instance 

    static int current_id = 1; //class level

    public Point(double init_x, double init_y) {
        x = init_x;
        y = init_y;
        id = current_id++;
    }

    public double getX() { return x; }
    public double getY() { return y; }

    public static Point centerOfMass(Point[] arr) {
        double center_x = 0, center_y = 0;
        for (int i = 0; i < arr.length ; ++i) {
            center_x += arr[i].getX();
            center_y += arr[i].getY();
        }
        center_x /= arr.length;
        center_y /= arr.length;

        return new Point(center_x, center_y);
    }

    @Override
    public String toString() {
        //1: (x,y) 
        return id + ": ( " + x + "," + y + " )";
    }
}
