public class PerfectNumRange {
    public static void main(String[] args){
        if (args.length == 1){    
            int n = Integer.parseInt(args[0]);
            int perfect = 0;
            for (int i=1; i<=n; i++){
            int temp = 0;
                for (int j=1; j<=i/2; j++){        
                    if(i%j == 0){
                        temp += j;    
                    }                
                }
                if (temp == i) {
                    perfect +=1;
                }                    
            }
            if (perfect == 0) {
                System.out.println("There is not a perfect number in the given interval.");
            }
            else {
                System.out.println("There is a " + perfect + " perfect number in the given interval.");
            }
        } else {
            System.err.println("Incorrect parameterization!");
            System.exit(0);
        }    
    } 
}