package travel.flying;


import java.util.Objects;

import travel.Destination;
import travel.DayAndTime;
import travel.DestinationUtils;

public class Plane extends Flight implements Flyable {
    private String name;
    private int id;
    private int ticketPrice;
    
    private Plane(String name, int id, int ticketPrice) throws IllegalArgumentException {
        super();
        if (name != null && ticketPrice >= 10) {
            this.name = name;
            this.id = id;
            this.ticketPrice = ticketPrice;
        } else
            throw new IllegalArgumentException("Name or Ticket Price invalid!");
    }

    public static Plane make(String data) {
        String[] parts = data.split(",");
        return new Plane(parts[0], Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
    }

    public int estimatedArrivalTime(Destination destination, DayAndTime departHour) {
        int rhour = Integer.parseInt(DestinationUtils.getRoundedHours(destination));
        int dhour = departHour.getHour();

        if (dhour + rhour >= 24)
            return (dhour + rhour - 24);
        return (dhour + rhour);
    }

    public double getPrice(double discountRate) {
        if (discountRate < 0 || discountRate > 1)
            throw new IllegalArgumentException("Discount rate must be between 0 and 1!");
        return this.ticketPrice - (this.ticketPrice * discountRate);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null)
            return false;
        if (obj == this)
            return true;
        if (obj instanceof Plane) {
            Plane objPlane = (Plane) obj;
            return this.id == objPlane.getId() && this.name.equals(objPlane.getName()) && this.ticketPrice == objPlane.getTicketPrice();
        } else
            return false;
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.name, this.id, this.ticketPrice);
    }

    @Override
    public String toString() {
        return this.name + "," + this.id + "," + this.ticketPrice;
    }

    public String getName() {
        return this.name;
    }

    public int getId() {
        return this.id;
    }

    public int getTicketPrice() {
        return this.ticketPrice;
    }
}