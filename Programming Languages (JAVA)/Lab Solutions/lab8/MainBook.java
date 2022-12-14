class Book {
    private String author, title;
    protected int pages;

    public Book() {
        this.author = "John Steinbeck";
        this.title = "Of Mice and Men";
        this.pages = 107;
    }

    public Book(String author, String title, int pages) {
        if (author.length() < 2 || title.length() < 4) {
            throw new IllegalArgumentException();
        }
        this.author = author;
        this.title = title;
        this.pages = pages;
    }

    public String getShortName() {
        return author.substring(0,2) + ":  " + title.substring(0,4) + " , consist of " + pages + "pages.";
    }

    public String createReference(String article, int from, int to) {
        return getShortName() + " [" + from + "-" + to + "] referenced in article: " + article;
    }

    @Override
    public String toString() {
        return author + " : " + title + ", pages: " + pages;
    }
}

enum CoverType {
    SOFTCOVER, HARDCOVER;
}

class PrintedBook extends Book {
    protected CoverType cover;

    public PrintedBook() {
        this.pages += 6;
        this.cover = CoverType.HARDCOVER;
    }

    public PrintedBook(String author, String title, int pages, CoverType cover) {
        super(author, title, pages);
        this.cover = cover;
    }

    public int getPrice() {
        if (cover == CoverType.SOFTCOVER) {
            return pages * 2;
        } else {
            return pages * 3;
        }
    }

    @Override
    public String createReference(String article, int from, int to) {
        return super.toString() + " [" + from + "-" + to + "] referenced in article: " + article;
    }


    @Override
    public String toString() {
        if (cover == CoverType.SOFTCOVER) {
            return super.toString() + "(SOFTCOVER)";
        } else {
            return super.toString() + "(HARDCOVER)";
        }
    }

}

class EBook extends Book {
    protected int PDFSize;

    public EBook(String author, String title, int pages, int PDFSize) {
        super(author, title, pages);
        this.PDFSize = PDFSize;
    }

    public int getPrice() {
        return pages + PDFSize;
    }

    @Override
    public String createReference(String article, int from, int to) {
        return super.toString() + " (PDF size: " + PDFSize + ") [" + from + "-" + to + "] referenced in article: " + article;
    }

    //Overloaded method
    //@Override, will give a compilation error
    public String createReference(String article, String date) {
        return super.toString() + " (PDF size: " + PDFSize + ") referenced in article: " + article + ", accessing PDF date: " + date;
    }


}

class MainBook {
    public static void main(String[] args) {
        Book book1 = new Book();
        Book book2 = new Book("author" ,"book title", 100);
        System.out.println("The book using the parameterless constructor: " + book1.getShortName());
        System.out.println("The book using the parameterized constructor: " + book2.getShortName());

        PrintedBook pb = new PrintedBook();
        PrintedBook pb2 = new PrintedBook("Aron", "Computer Science", 100, CoverType.SOFTCOVER);
        System.out.println("The printed book using the parameterized constructor: " + pb2.getShortName());
        System.out.println("The printed book (with softcover) price is: " + pb2.getPrice());
        System.out.println("The printed book price is: " + pb.getPrice());

        EBook ebook = new EBook("Sam", "history", 150, 15);
        System.out.println("The e book  price is: " + ebook.getPrice());

        System.out.println(book1.createReference("The book name", 5, 100));
        System.out.println(book2.createReference("The book name", 5, 100));
        System.out.println(ebook.createReference("The book name", 5, 100));
        System.out.println(ebook.createReference("The book name", "2020/04/11"));





    }
}