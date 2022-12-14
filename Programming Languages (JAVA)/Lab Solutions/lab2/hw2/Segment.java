class Segment {
  double x1, y1, x2, y2;
  Line line() {
    //y=-ax/b+c/b
    //y=mx+b
    //y1=mx1+b y2=mx2+b
    //y1-mx1=y2-mx2
    //y2-y1=mx2-mx1, m=(y2-y1)/(x2-x1)
    //b=y2-mx2 or b=y1-mx1
    Line l = new Line();
    l.a = -(y2-y1);
    l.b = x2-x1;
    //c=(y1-mx1)*l.b
    l.c = y1 * l.b + l.a * x1;
    return l;
  }
  boolean contains(Point p) {
    return (p.x >= x1 && p.x <= x2 || p.x >= x2 && p.x <= x1) && (p.y >= y1 && p.y <= y2 || p.y >= y2 && p.y <= y1) && line().contains(p);
  }
  int orientation(Point p) {
    double o = (y2-y1)*(p.x-x2)-(p.y-y2)*(x2-x1);
    if (o == 0) return 0;
    return o > 0 ? 1 : -1;
  }
  boolean intersect(Segment s)
  {
    Point p = new Point(), q = new Point();
    p.x = s.x1; p.y = s.y1;
    q.x = s.x2; q.y = s.y2;
    Point ps = new Point(), qs = new Point();
    ps.x = x1; ps.y = y1;
    qs.x = x2; qs.y = y2;
    int o1 = orientation(p), o2 = orientation(q), o3 = s.orientation(ps), o4 = s.orientation(qs);
    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
      return (x1 >= s.x1 && x2 <= s.x1 || x2 >= s.x1 && x1 <= s.x1 || x1 >= s.x2 && x2 <= s.x2 || x2 >= s.x2 && x1 <= s.x2) && (y1 >= s.y1 && y2 <= s.y1 || y2 >= s.y1 && y1 <= s.y1 || y1 >= s.y2 && y2 <= s.y2 || y2 >= s.y2 && y1 <= s.y2);
    }
    return o1 != o2 && o3 != o4;
  }
}