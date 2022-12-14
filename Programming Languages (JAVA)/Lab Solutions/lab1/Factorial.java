class Factorial {
    public static int fact(int n) {
        if (n == 0) return 1;
        return n * fact(n-1); 
    }

    public static int fact2(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) 
            fact *=i; // fact = fact * i;
            return fact;
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Invalid");
            System.exit(0);
        } else {
            int N = Integer.parseInt(args[0]);
            if (N>=0 && N <= 10) {
                System.out.println(N + "!= " + fact(N) + " With recursion!");
                System.out.println(N + "!= " + fact2(N) + " Without recursion!");
            }
        }
    }
}