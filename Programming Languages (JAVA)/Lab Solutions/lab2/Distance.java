class Distance {
    public static void main(String[] args) {

        //handle the case when the number of args is odd
        double dist = 0;

        for (int i = 0; i < args.length-2; i=i+2) {
            Point p1 = new Point();
            p1.x = Integer.parseInt(args[i]);
            p1.y = Integer.parseInt(args[i+1]);

            Point p2 = new Point();
            p2.x = Integer.parseInt(args[i+2]); //3ed
            p2.y = Integer.parseInt(args[i+3]); //4th

            dist += p1.distance(p2);
        }

        System.out.println(dist);
    }
}