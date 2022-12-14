class MainCircle {
    public static void main(String[] args) {
        Circle circle = new Circle();
        circle.x = 2;
        circle.y = 3;
        circle.radius = 20;

        System.out.println("The area of the circle is:" + circle.getArea());

        circle.enlarge(2);
        System.out.println("The area of the circle after using enlarge:" + circle.getArea());

    }
}