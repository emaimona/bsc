class Test {
    public static void main(String[] args) {

        try {
            int value = 100/0;
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }
        
        System.out.println("the rest of the program");
    }
}