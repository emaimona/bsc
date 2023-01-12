package travel;

import java.util.ArrayList;
import java.util.List;

//import assignment2.travel.Destination;

public class DestinationUtils {
    private final static ArrayList<String> durations = new ArrayList<>( List.of("BERLIN      01:34", "ROME        01:45", "AMSTERDAM   02:05", "PARIS       02:20", "HELSINKI    02:43"));
    
    public static String getDestination(String duration) {

        for (String dest: durations) {
            int idx = dest.indexOf(":");
            String time = dest.substring(idx-2);
            if (time.equals(duration)) {
                return dest.split(" ")[0];
            }
        }
        return null;
    }


    public static String getDestinationDuration(Destination destination) {
        for (String dest: durations) {
            if (dest.split(" ")[0].equals(destination.toString())) {
                int idx = dest.indexOf(":");
                return dest.substring(idx-2);
            }
        }
        return null;
    }

    public static String getRoundedHours(Destination destination) {
        String duration = getDestinationDuration(destination);
        int hour = Integer.parseInt(duration.substring(0, 2));
        int minutes = Integer.parseInt(duration.substring(3));
        if (minutes >= 30)
            return (hour+1) + "";
        else
            return hour + "";
    }
}
