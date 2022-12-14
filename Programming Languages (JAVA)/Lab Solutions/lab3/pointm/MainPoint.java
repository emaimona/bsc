package pointm;
import point2d.Point;

class MainPoint {
    public static void main(String[] args) {
        Point point = new Point(); //
        point.x = 3;
        point.y = 3;
        point.move(1,1);
        System.out.println(point.x + " " + point.y); //4,4
        point.mirror(1,3);
        System.out.println(point.x + " " + point.y); //-2,2
        point.mirror(0,0);
        System.out.println(point.x + " " + point.y); //2,-2
        System.out.println("---------------");
        //for task2 
        Point point2 = new Point();
        point2.x = 2;
        point2.y = 8;
        point.mirror(point2);
        System.out.println(point.x + " " + point.y);
        System.out.println(point.distance(point2)); //

    }
}