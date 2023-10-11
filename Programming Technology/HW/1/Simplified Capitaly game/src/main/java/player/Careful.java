package player;

import field.Field;

public class Careful extends Player {
    public Careful(String name) {
        super(name);
    }

    @Override
    public void applyStrategy(Field field) {
        if (field.isProperty())
            super.applyStrategyCarefully(field);
        field.processField(this);
    }

    /**
     * Get the player's money
     * @return the half of the money of the player,
     * because he buys iff half of money is greater than or equal to the cost.
     */
    @Override
    public int getMoney() {
        return super.getMoney();
    }

    @Override
    public String toString() {
        return "Careful " + super.toString();
    }
}
