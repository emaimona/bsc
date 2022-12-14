package Final_Practical_exam.exercise.counter;

public enum Category {
    LETTER, WHITESPACE, OTHER;

    public static Category determineCategory(char character) {
        if (Character.isLetter(character)) {
  	                        return LETTER;
  	                } else if (Character.isWhitespace(character)) {
  	                        return WHITESPACE;
  	                } else {
  	                        return OTHER;
                   }
    }
}