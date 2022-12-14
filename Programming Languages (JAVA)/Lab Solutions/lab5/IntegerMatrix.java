/**
  * @author Midya Alqaradaghi
  * @since 3.0
  * @version 3.0
 */
public class IntegerMatrix {
    private int rowNum;
    private int colNum;
    private int[][] data; // 1 2 3
                          // 4 5 6
    /**
    * <p> Store the given ID array as a Matrix. </p>
    * @param rowNum number of rows
    * @param colNum number of columns
    * @param linearData integers stored in 1D array
    * @since 1.0
     */
    public IntegerMatrix(int rowNum, int colNum, int[] linearData) { // 1 2 3 4 5 6
        if (rowNum*colNum != linearData.length) {
            throw new IllegalArgumentException("rowNum*colNum should be == linearData.length");
        }
        this.rowNum = rowNum;
        this.colNum = colNum;
        data = new int[rowNum][colNum];

        for (int i = 0; i < linearData.length; i++ ) {
            int row = (int) Math.floor(i / colNum); // 0 0 0
            int col = i % colNum;
            System.out.println(i + " " + row + " " + col);
            data[row][col] = linearData[i];
        }
    }

    /**
    * <p> Converts the matrix elements to string with proper formatting, initial version. </p>
    * @return the matrix items converted to String
    * @since 1.0
     */

    @Override 
    public String toString(){
        StringBuilder sb = new StringBuilder();
        String rowDelim = "";
        String colDelim = "";

        for(int[] row : data){
            sb.append(rowDelim);
            rowDelim = ";";
            for(int elem : row){
                sb.append(colDelim);
                colDelim = ",";
                sb.append(elem);
            }
            colDelim = "";
        }

        return sb.toString();
    }
}