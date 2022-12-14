public class Adder {
    public static String add(final String s1, final String s2) {
        try {
            return Integer.toString(Integer.parseInt(s1) + Integer.parseInt(s2));
        } catch(NumberFormatException e) {
            try {
                return Double.toString(Double.parseDouble(s1) + Double.parseDouble(s2));
            } catch (NumberFormatException e2) {
                throw new IllegalArgumentException("One or both of the passed parameters were not numbers!");
            }
        }
    }
}