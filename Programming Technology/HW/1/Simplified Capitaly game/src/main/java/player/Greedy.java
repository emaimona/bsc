package player;

import field.Field;

public class Greedy extends Player {
    public Greedy(String name) {
        super(name);
    }

    @Override
    public void applyStrategy(Field field) {
        if (field.isProperty())
            super.applyStrategy(field);
        field.processField(this);
    }

    @Override
    public String toString() {
        return "Greedy " + super.toString();
    }
}
