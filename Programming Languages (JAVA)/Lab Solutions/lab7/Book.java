class Book {
    static enum Genre {
        FANTASY, SATIRE, SCIFI, PHILOSOPHY, EDUCATIONAL;
    }
    private String author;
    private String title;
    private int reservePrice;
    private int id;
    private Genre genre;

    private static int lastId;
    public static void resetId() { lastId = 0; }

    public int getReservePrice() { return reservePrice; }
    public int getId() { return id; }

    private Book(String author, String title, Genre genre, int reservePrice ) {
        this.author = author;
        this.title = title;
        this.reservePrice = reservePrice;
        this.genre = genre;
        id = lastId++;
    }

    public static Book make(String name, String title, String genreN, String reservePriceStr ) {
        try {
            int reservePrice = Integer.parseInt(reservePriceStr);
            if (name == null || title == null || title.length() < 2 || reservePrice <= 0 ) return null;

            Genre g = Genre.valueOf(genreN);
            int i = 0;
            while (i < title.length()) {
                if (Character.isLetter(title.charAt(i)) || Character.isDigit(title.charAt(i)) || Character.isWhitespace(title.charAt(i))) {
                    ++i;
                } else {
                    return null;
                }
            } return new Book(name, title, g, reservePrice);
        } catch(NumberFormatException e) {
            return null;
        } catch (IllegalArgumentException e) {
            return null;
        }

    }

    public static boolean isSameGenre( Book b1, Book b2) {
        return b1.genre == b2.genre;
    }

    public int compare(Book that) {
        if (!isSameGenre(this, that)) {
            throw new IllegalArgumentException();
        }
        return Integer.compare(reservePrice, that.reservePrice);
    }
}