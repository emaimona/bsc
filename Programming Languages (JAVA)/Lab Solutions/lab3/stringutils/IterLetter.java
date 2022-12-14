package stringutils;

public class IterLetter {
    private String str;
    private int counter;

    public IterLetter(String str) {
        if (str == null) {
           throw new IllegalArgumentException("Invalid String!!");
        }
        this.str = str;
        this.counter = 0;
    }

    public void restart() { //Mi  restart Midya
        counter = 0;
    }

    public boolean hasNext() {
        return counter < str.length();
    }

    public void printNext() { //Imre
        if (hasNext()) {
            System.out.println(str.charAt(counter++)); //not ++ counter
        }
    }
}