package field;

import player.Player;

public class Service extends Field {
    private int cost;

    public Service(int cost) {
        if (cost < 0)
            throw new IllegalArgumentException("Cost cannot be negative");
        this.cost = cost;
    }

    public int getCost() {
        return cost;
    }

    /**
     * Process service field logic
     * @param player
     */
    @Override
    public void processField(Player player) {
        player.payBank(this.cost);
        player.declareBankruptcy();
    }
}