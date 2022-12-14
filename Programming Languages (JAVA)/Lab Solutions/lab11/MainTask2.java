interface Reversable {
    void reverse();
}
class ReversablePoint implements Reversable {
    private int x,y;
    private int prev_x, prev_y;

    public ReversablePoint(int x, int y) {
        prev_x = this.x = x;
        prev_y = this.y = y;
    }

    public void setX(int x)
    {
        prev_x = this.x;
        this.x = x;
    }

    public void setY(int y)
    {
        prev_y = this.y;
        this.y = y;
    }

    public int getX() { return x; }
    public int getY() { return y; }

    public void reverse() {
        x = prev_x;
        y = prev_y;
    }
}

interface Printable {
    void print();
}

class PrintablePoint implements Printable {
    private int x, y;

    public PrintablePoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void print() {
        System.out.println("(" + x + "," + y + ")");
    }

}

class Book implements Printable {
    private String author, title;

    public Book(String author, String title)
    {
        this.author = author;
        this.title = title;
    }

    public void print() {
        System.out.println(author + ": " + title);
    }

}

class PrintableAndReversablePoint implements Printable, Reversable {
    private int x, y;
    private int prev_x, prev_y;

    public PrintableAndReversablePoint(int x, int y) {
        prev_x = this.x = x;
        prev_y = this.y = y;
    }

    public void setX(int x)
    {
        prev_x = this.x;
        this.x = x;
    }

    public void setY(int y)
    {
        prev_y = this.y;
        this.y = y;
    }

    public int getX() { return x; }
    public int getY() { return y; }

    public void print() {
        System.out.println("(" + x + "," + y + ")");
    }

    public void reverse() {
        x = prev_x;
        y = prev_y;
    }
}

class MainTask2 {
    public static void main(String[] args) {
        ReversablePoint point1 = new ReversablePoint(2,3);
        System.out.println("x = "+ point1.getX()); //2
        point1.setX(-20);
        System.out.println("x = "+ point1.getX()); //-20
        point1.reverse();
        System.out.println("x = "+ point1.getX()); //2

        System.out.println("++++++");

        PrintableAndReversablePoint p = new PrintableAndReversablePoint(20,30);
        p.print();
        p.setX(3);
        p.print();
        p.setX(-4);
        p.setY(-4);
        p.print();
        p.reverse();
        p.print();
    }
    

}