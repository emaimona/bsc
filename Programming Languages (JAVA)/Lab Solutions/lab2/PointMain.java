class PointMain {
    public static void main(String[] args) {
        Point point = new Point();
        point.x = 3;
        point.y = 3;

        System.out.println(point.x + " " + point.y); //3,3
        point.move(1,1);
        System.out.println(point.x + " " + point.y); //4,4
        point.mirror(1,3); //reflection point values
        System.out.println(point.x + " " + point.y); //-2,2
        point.mirror(0,0);
        System.out.println(point.x + " " + point.y); //2,-2

        System.out.println("----------------");
        Point point2 = new Point();
        point2.x = 2;
        point2.y = 5;
        System.out.println("The distance between point and point2 is: "+point.distance(point2)); //distance between point and point2

        point.mirror(point2);
        System.out.println(point.x + " " + point.y);



    }
}