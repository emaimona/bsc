package field;

import player.Player;


public class Lucky extends Field {
    private final int amount;

    public Lucky(int amount) {
        if (amount < 0)
            throw new IllegalArgumentException("Amount cannot be negative");
        this.amount = amount;
    }

    public int getAmount() {
        return this.amount;
    }

    /**
     * Process lucky field logic
     * @param player
     */
    @Override
    public void processField(Player player) {
        player.increaseMoney(this.amount);
    }
}
