class Greeting2 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Invalid number of command args!");
        } else {
            System.out.println("Hello " +args[0] + "!");
        }
    }
}