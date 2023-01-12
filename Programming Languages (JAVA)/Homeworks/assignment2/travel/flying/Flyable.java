package travel.flying;

import travel.Destination;
import travel.DayAndTime;

public interface Flyable {
    public int estimatedArrivalTime(Destination destination, DayAndTime departHour);
    public double getPrice(double discountRate);
}