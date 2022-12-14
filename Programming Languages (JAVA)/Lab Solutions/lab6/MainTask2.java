import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

//import java.io.*;

class MainTask2 {
    public static void main(String[] args) {
        File input = new File(args[0]);
        File output = new File(args[1]);

        try {
            BufferedReader br = new BufferedReader(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");

                int sum = 0;
                for (String num: parts) {
                    sum += Integer.parseInt(num);
                }
                //System.out.println(sum);
                pw.println(sum);
            }
            br.close();
            pw.close(); //this is not good place for closing my resources
        } catch (FileNotFoundException e) {
            System.out.println("unable to access file" + args[0]);
        } catch (IOException e) {
            System.out.println("IO Error!");
        }
    }
}