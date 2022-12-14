public class Line {
	double a, b, c;

	boolean contains( Point p ) {
		return a*p.x + b*p.y == c;
	}
	/* Ax+B=y ax + by = c (-a/b)x + c/b = y
    * parallel if the slope (A) is the same
    * if b==0, then it is vertical */
	boolean isParallelWith( Line that ){
		return (this.a * that.b == that.a * this.b);
	}

	boolean isOrthogonalTo( Line that ){
		return (this.a * that.a + this.b * that.b == 0);
	}
}