package exercise.counter;

public enum Category {
    LETTER, WHITESPACE, OTHER;

    //public static Category Category;

    public static Category determineCategory(char chr) {
        if (Character.isLetter(chr))
            return Category.LETTER;
        else if (Character.isWhitespace(chr))
            return Category.WHITESPACE;
        else
            return Category.OTHER;
    }
}