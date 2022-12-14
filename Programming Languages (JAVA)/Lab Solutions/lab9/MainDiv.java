import java.util.LinkedList;

class MainDiv {
    public static LinkedList<Integer> divisor(int num) {
        LinkedList<Integer> result = new LinkedList<>();
        for (int i = 1; i <= num; ++i) {
            if (num % i == 0) {
                result.add(i);
            }
        } return result;
    }

    public static void main(String[] args) {
        System.out.println(divisor(10));
        System.out.println(divisor(1));
        System.out.println(divisor(7));
        System.out.println(divisor(124));
    }
}