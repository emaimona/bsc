package rental;
import java.io.*;
import java.util.*;

class CarRental {
    private String name;
    private ArrayList<Car> cars;

    public CarRental(String name, String filename) {
        this.name = name;
        try {
            Scanner s = new Scanner(new File(filename));
            while (s.hasNextLine()) {
                Car c = Car.make(s.nextLine());
                if (c != null)
                    cars.add(c);
            }
        } catch (FileNotFoundException e) {

        }
    }

    public double averagePrice() {
        if (cars.isEmpty()) return -1.0;
        else {
            int sum = 0;
            for (Car c: cars)
                sum += c.getPrice();
            return (double) sum/cars.size();
        }
    }

    public Car rentCheapest() {
        if (cars.isEmpty())
            return null;
        else {
            Car cheapest = cars.get(0);
            int cheapestOneIndex = 0;
            for (int i = 1; i < cars.size(); i++) {
                Car c = cars.get(i);
                if (c.isCheaperThan(cheapest)) {
                    cheapest = c;
                    cheapestOneIndex = i;
                }
            }
            return cars.remove(cheapestOneIndex);

        }
    }

    public String toString() {
        return String.format("CarRental(%s, %s)", name, cars);
    }
}