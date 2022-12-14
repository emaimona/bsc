class SegMain {
  public static void main(String[] args)
  {
    Segment s1 = new Segment();
    s1.x1 = 2; s1.y1 = 2; s1.x2 = 4; s1.y2 = 4;
    Point p1 = new Point(), p2 = new Point();
    p1.x = 1; p1.y = 1;
    p2.x = 3; p2.y = 3;
    Line l = s1.line();
    System.console().printf("%f %f %f\n", l.a, l.b, l.c);
    System.console().printf("%s %s\n", !s1.contains(p1) ? "true" : "false", s1.contains(p2) ? "true" : "false");
    System.console().printf("%d %d\n", s1.orientation(p1), s1.orientation(p2));
    Segment s2 = new Segment();
    s2.x1 = 3; s2.y1 = 3; s2.x2 = 5; s2.y2 = 5;
    Segment s3 = new Segment();
    s3.x1 = 5; s3.y1 = 5; s3.x2 = 7; s3.y2 = 7;
    Segment s4 = new Segment();
    s4.x1 = 1; s4.y1 = 3; s4.x2 = 3; s4.y2 = 1;
    Segment s5 = new Segment();
    s5.x1 = 11; s5.y1 = 13; s5.x2 = 13; s5.y2 = 11;
    System.console().printf("%s %s %s %s\n", s1.intersect(s2) ? "true" : "false", !s1.intersect(s3) ? "true" : "false", s1.intersect(s4) ? "true" : "false", !s1.intersect(s5) ? "true" : "false");
  }
}