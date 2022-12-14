class PointMain {
    public static void main(String[] args) {

        System.out.println("Enter the number of Points in the array");
        int num = Integer.parseInt(System.console().readLine());
        Point[] arr = new Point[num];

        for (int i = 0; i < num; ++i) {
            System.out.println("Enter x:");
            double x = Double.parseDouble(System.console().readLine());
            System.out.println("Enter y:");
            double y = Double.parseDouble(System.console().readLine());

            arr[i] = new Point(x,y);
        }

        Point center = Point.centerOfMass(arr); //3
        System.out.println("The center of the mass: " + center);
    }
}