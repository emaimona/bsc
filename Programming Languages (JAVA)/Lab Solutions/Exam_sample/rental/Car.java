package rental;

public class Car {
    private String licensePlate;
    private int price;

    public Car(String licensePlate, int price) {
        this.licensePlate = licensePlate;
        this.price = price;
    }

    public static Car make(String data) {
        String[] parts = data.split(":");
        if (parts.length == 2) {
            try {
                String licensePlate = parts[0];
                int price = Integer.parseInt(parts[1]);
                if (price > 0 && licensePlate.length() == 6)
                    return new Car(licensePlate, price);
            } catch (NumberFormatException e) {

            }
            return null;
        } else return null;
    }

    public int getPrice() {
        return price;
    }
    public String getLicensePlate() {
        return licensePlate;
    }

    public boolean isCheaperThan(Car other) {
        return (price < other.price);
    }

    public String toString() { //Car(DEF123,500)`
        return String.format("Car(%s,%d)", licensePlate, price);
    }
}