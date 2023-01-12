package travel.flying;

import travel.Destination;
import travel.DayAndTime;
import travel.DestinationUtils;

public class Flight {
    protected String name;
    protected Destination destinationCity;
    protected int numberOfTravellers;
    protected DayAndTime flightDayAndTime;

    public Flight(String name, Destination destinationCity, int numberOfTravellers, DayAndTime flightDayAndTime) throws IllegalArgumentException {
        if (numberOfTravellers >= 15 && numberOfTravellers <= 100) {
            this.name = name;
            this.destinationCity = destinationCity;
            this.numberOfTravellers = numberOfTravellers;
            this.flightDayAndTime = flightDayAndTime;
        } else
            throw new IllegalArgumentException("Number of travellers out of range <15 Or >100");
    }

    public Flight() {
        this("AirBus", Destination.ROME, 83, new DayAndTime());
    }

    public String getFlightDuration() {
        return DestinationUtils.getDestinationDuration(this.destinationCity);
    }

    public String getName() {
        return this.name;
    }

    public Destination getDestinationCity() {
        return this.destinationCity;
    }

    public int getNumberOfTravellers() {
        return this.numberOfTravellers;
    }

    public String getFlightDayAndTime() {
        return this.flightDayAndTime.toString();
    }


    @Override
    public String toString() {
        return "Flying " + this.name + " with " + this.numberOfTravellers + " passengers to " + this.destinationCity + " on " + this.flightDayAndTime;
    }

}