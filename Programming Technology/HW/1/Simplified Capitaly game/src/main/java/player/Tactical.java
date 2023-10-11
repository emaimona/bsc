package player;

import field.Field;

public class Tactical extends Player {
    private int chance = 0;
    public Tactical(String name) {
        super(name);
    }

    /**
     * Apply strategy based on the value of chance
     * and process field logic
     * @param field
     */
    @Override
    public void applyStrategy(Field field) {
        chance++;
        if (field.isProperty() && chance % 2 == 0)
            super.applyStrategy(field);
        field.processField(this);
    }

    @Override
    public String toString() {
        return "Tactical " + super.toString();
    }
}