package travel.flying;

import java.util.ArrayList;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

import travel.flying.Flight;
import travel.flying.Plane;
import travel.Destination;
import travel.DayAndTime;

public class FlightWithManyPlanes extends Flight {
    private ArrayList<Plane> planes;

    public FlightWithManyPlanes(String name, Destination destinationCity, int numberOfTravellers, DayAndTime flightDateAndTime, ArrayList<Plane> planes) {
        super(name, destinationCity, numberOfTravellers, flightDateAndTime);
        this.planes = planes;
    }

    public void save(String filename) throws IOException {
        PrintWriter pw = null;
        try {
            pw = new PrintWriter(new File(filename));
            pw.println(this.name);
            pw.println(this.destinationCity.name());
            pw.println(this.numberOfTravellers);
            pw.println(this.flightDayAndTime);

            for (Plane p: this.planes) {
                pw.println(p.toString());
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
        } finally {
            pw.close();
        }
    }


    public void load(String filename) throws IOException {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filename));
            this.name = br.readLine();
            this.destinationCity = Destination.valueOf(br.readLine()); //* not */
            this.numberOfTravellers = Integer.parseInt(br.readLine());
            br.readLine(); // Ignoring Date and Time

            String line;
            planes.clear();
            while ((line = br.readLine()) != null) {
                planes.add(Plane.make(line));
            }

        } catch(IOException e) {
            System.out.println(e.getMessage());
        } finally {
            br.close();
        }
        
    }

    public Plane getCheapestRide(double discountRateIncrease) throws IllegalStateException {
        /* 
         * I have decided to not change the value of the ticket but rather just calculate the discount,
         * because getMethod should be readonly by convention.
         */

        Plane cheapest = null;
        Double minCost = Double.MAX_VALUE; // maximum cost
        double discount = 0;

        if (planes.size() == 0)
            throw new IllegalStateException("The number of planes is zero!");
        else {
            for (int i=0; i<planes.size(); i++) {
                double price = planes.get(i).getPrice(discount);
                System.out.println(price + " "+planes.get(i).toString());
                if (price <= minCost) {
                    minCost = price;
                    cheapest = planes.get(i);
                }

                discount += discountRateIncrease;
            }
        }

        return cheapest;
    }

    public ArrayList<Plane> getPlanes() {
        return this.planes;
    }

}