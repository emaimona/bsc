import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class MathUtilsTest {
    public static final double EPSILON = 0.01;

    @Test 
    public void testPosRaisedToPos() {
        //power(2,3)
        assertEquals(8, MathUtils.power(2,3), EPSILON);
    }

    @Test
    public void testPosRaisedToZero() {
        //power(2,0) -> 1
        assertEquals(1, MathUtils.power(2, 0), EPSILON);
    }

    @Test
    public void testZeroRaisedToPos() {
        //power(0,2)
        assertEquals(0, MathUtils.power(0, 2765), EPSILON);
    }

    @Test
    public void testZeroRaisedToZero() {
        //power(0,0)
        assertEquals(1, MathUtils.power(0,0), EPSILON);
    }

    @Test
    public void testOneRaisedToPos() {
        //power(1, 456)
        assertEquals(1, MathUtils.power(1, 2345), EPSILON);
    }

    @Test 
    public void testPosRaisedToNeg() {
        //power(2,-2) -> 0.25
        assertEquals(0.25, MathUtils.power(2, -2), EPSILON);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testZeroRaisedToNeg() {
        //power(0,-2)
        MathUtils.power(0, -2);
    }


}