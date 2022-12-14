//Exercise 1 solution
class PerfectNum {
    public static void main(String[] args){
        if (args.length == 1){
            int n = Integer.parseInt(args[0]);
            int temp = 0;
            for(int i=1; i<=n/2; i++){
                if(n%i == 0){
                    temp += i;
                }
            }
            if (temp == n) {
                System.out.println("Th number is perfect.");
            } 
            else {
                System.out.println("The number is not perfect.");
            }
        } else {
            System.err.println("Incorrect parameterization!");
            System.exit(0);
        }
    }
}