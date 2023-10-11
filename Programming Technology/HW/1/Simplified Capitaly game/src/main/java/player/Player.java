package player;

import field.Field;
import field.Property;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import static util.ConfigurationConstants.*;

public abstract class Player {
    private final String name;
    private int money = STARTING_MONEY;
    private List<Property> properties = new ArrayList<>();

    protected Player(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public int getMoney() {
        return this.money;
    }
    public List<Property> getProperties() {
        return this.properties;
    }

    /**
     * Add a property to the player's list
     * @param property the property to add
     */
    public void addProperty(Property property) {
        this.properties.add(property);
    }

    /**
     * Remove a property from the player's list
     * @param property the property to remove
     */
    public void removeProperty(Property property) {
        this.properties.remove(property);
    }

    /**
     * Buy a property
     * @param property the property to buy
     */
    public void buyProperty(Property property) {
        if (property.getOwner() != null)
            return;
        property.setOwner(this);
        properties.add(property);
        decreaseMoney(COST_OF_UNOWNED_PROPERTY);
    }

     /**
     * Pay fine to the owner
     * @param owner the owner of the property
     * @param amount the amount to pay
     */
    public void payOwner(Player owner, int amount) {
        decreaseMoney(amount);
        owner.increaseMoney(amount);
    }

    /**
     * Check if the player is bankrupt
     * @return true if the money is less than or equal to 0, false otherwise
     */
    public boolean isBankrupt() {
        return money <= 0;
    }

    /**
     * Increase the player's money by the given amount
     * @param amount the amount to increase the player's money by
     */
    public void increaseMoney(int amount) {
        this.money += amount;
    }

    /**
     * Decrease the player's money by the given amount
     * @param amount the amount to decrease the player's money by
     */
    public void decreaseMoney(int amount) {
        this.money -= amount;
    }

    /**
     * Decrease the player's money by the given amount
     * @param cost
     */
    public void payBank(int cost) {
        this.money -= cost;
    }

    /**
     * Declare bankruptcy
     * Remove all properties from the player's list, and set their owner to null
     */
    public void declareBankruptcy() {
        if (!this.isBankrupt())
            return;

        properties.forEach(property -> property.setOwner(null));
        properties.clear();
    }

    /**
     * Apply the player's strategy, if the field is a property
     * throws an exception if the field is not a property
     * @param field the field to apply the strategy on
     */
    public void applyStrategy(Field field) {
        Property property = (Property) field;
        if (property.getOwner() == null && this.getMoney() >= COST_OF_UNOWNED_PROPERTY) {
            property.setOwner(this);
            this.addProperty(property);
            this.payBank(COST_OF_UNOWNED_PROPERTY);
        } else if (property.getOwner() != null
                && !property.getOwner().equals(this)
                && this.getMoney() >= COST_OF_BUILDING_A_HOUSE) {
            property.setHasHouse(true);
            this.payBank(COST_OF_BUILDING_A_HOUSE);
        }
    }

    /**
     * Apply the careful player's strategy, if the field is a property
     * throws an exception if the field is not a property
     * @param field the field to apply the strategy on
     */
    public void applyStrategyCarefully(Field field) {
        Property property = (Property) field;
        if (property.getOwner() == null && this.getMoney() / 2 >= COST_OF_UNOWNED_PROPERTY) {
            property.setOwner(this);
            this.addProperty(property);
            this.payBank(COST_OF_UNOWNED_PROPERTY);
        } else if (property.getOwner() != null
                && !property.getOwner().equals(this)
                && this.getMoney() / 2 >= COST_OF_BUILDING_A_HOUSE) {
            property.setHasHouse(true);
            this.payBank(COST_OF_BUILDING_A_HOUSE);
        }
    }

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name + '\'' +
                ", money=" + money +
                ", Number of properties=" + properties.size() +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Player player = (Player) o;
        return money == player.money && Objects.equals(name, player.name) && Objects.equals(properties, player.properties);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, money, properties);
    }
}
