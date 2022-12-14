import stringutils.IterLetter;

public class StrMain {
    public static void main(String[] args) {
        IterLetter it = new IterLetter("Ahmed");

        it.printNext(); //A
        it.printNext(); //h
        it.printNext(); //m

        it.restart(); //counter = 0
        while (it.hasNext()) {
            it.printNext(); // A h m e d
        }

    }
}