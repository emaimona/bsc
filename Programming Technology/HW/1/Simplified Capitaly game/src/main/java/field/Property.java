package field;

import player.Player;

import static util.ConfigurationConstants.COST_OF_STEPPING_INTO_ONES_PROPERTY_WITHOUT_HOUSE;
import static util.ConfigurationConstants.COST_OF_STEPPING_INTO_ONES_PROPERTY_WITH_HOUSE;

public class Property extends Field {
    private Player owner;
    private boolean hasHouse;

    public Player getOwner() {
        return this.owner;
    }

    public void setOwner(Player owner) {
        this.owner = owner;
    }

    public boolean hasHouse() {
        return this.hasHouse;
    }

    public void setHasHouse(boolean hasHouse) {
        this.hasHouse = hasHouse;
    }

    /**
     * Check if the field is a property.
     * @return True
     */
    @Override
    public boolean isProperty() {
        return true;
    }

    /**
     * Process the Property field logic
     * @param player
     */
    @Override
    public void processField(Player player) {
        if (this.owner != null && !this.owner.equals(player)) {
            if (this.hasHouse) {
                player.payOwner(owner, COST_OF_STEPPING_INTO_ONES_PROPERTY_WITH_HOUSE);
            } else {
                player.payOwner(owner, COST_OF_STEPPING_INTO_ONES_PROPERTY_WITHOUT_HOUSE);
            }
            player.declareBankruptcy();
        }
    }
}
