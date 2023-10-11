package util;

import exception.InvalidStrategyException;
import player.Careful;
import player.Greedy;
import player.Player;
import player.Tactical;


public class CustomFunctions {
    private CustomFunctions() {}

    /**
     * Get new player
     * @param name player name based on strategy
     * @param strategyName player strategy
     * @return new player
     * @throws InvalidStrategyException if strategy is invalid
     */
    public static Player getNewPlayer(String name, String strategyName) throws InvalidStrategyException {
        if (strategyName.equals("Greedy")) {
            return new Greedy(name);
        } else if (strategyName.equals("Careful")) {
            return new Careful(name);
        } else if (strategyName.equals("Tactical")) {
            return new Tactical(name);
        } else
            throw new InvalidStrategyException("Invalid strategy");
    }
}