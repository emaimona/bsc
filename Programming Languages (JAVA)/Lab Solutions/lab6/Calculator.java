class Calculator {
    public static void main(String[] args) {
        try {
            if (args.length != 3) {
            throw new IllegalArgumentException("");
        } else {
            double a = Double.parseDouble(args[0]);
            char m = args[1].charAt(0);
            double b = Double.parseDouble(args[2]);

            System.out.println("" + a + m + b + " = "); //a / b = 

            switch(m) {
                case '+':
                    System.out.println("a+b=" + (a+b));
                    break;
                case '-':
                    System.out.println("a-b=" + (a-b));
                    break;
                case '*':
                    System.out.println("a*b=" + (a*b));
                    break;
                case '/':
                    if (b == 0) { 
                        throw new ArithmeticException();
                    }
                    System.out.println(a/b);
                    break;
                default:
                    throw new IllegalArgumentException();
            }            
        }
    } catch(NumberFormatException e) {
        System.out.println("Invalid number format.");
         System.out.println(e.getMessage());
    } catch (IllegalArgumentException e) {
        System.out.println("Invalid program arguments provided.");
         System.out.println(e.getMessage());
    } catch (ArithmeticException e) {
        System.out.println("Arithmetic error occured.");
         System.out.println(e.getMessage());
    }
 }
       
}