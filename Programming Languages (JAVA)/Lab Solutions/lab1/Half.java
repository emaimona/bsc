class Half {
    public static void main(String[] args) {
        int from, to;
        from = Integer.parseInt(System.console().readLine("Give me the lower bound:"));
        to = Integer.parseInt(System.console().readLine("Give me the upper bound:"));

        for (int index = from; index <= to; ++index) {
            System.out.println("The half of " + index + " is " + index/2.0);
        }
    }
}