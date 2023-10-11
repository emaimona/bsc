package field;

import player.Player;

public abstract class Field {
    /**
     * Process the field logic implemented by the child class.
     */
    public abstract void processField(Player player);

    /**
     * Check if the field is a property.
     * @return false, to be overridden by Property
     */
    public boolean isProperty() {
        return false;
    }
}
