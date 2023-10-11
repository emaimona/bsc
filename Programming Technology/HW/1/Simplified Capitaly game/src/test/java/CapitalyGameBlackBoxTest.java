import field.Field;
import field.Property;
import game.CapitalyGame;
import org.junit.jupiter.api.Test;
import player.Player;

import static org.junit.jupiter.api.Assertions.*;
import static util.ConfigurationConstants.*;

class CapitalyGameBlackBoxTest {
    @Test
    void testPlayerTurnAndPropertyPurchase() {
        CapitalyGame game = new CapitalyGame();
        try {
            game.loadGameParameters("input-1.txt", "roll_dices-1.txt");

            while (!game.isGameOver()) {
                Player currentPlayer = game.getCurrentPlayer();
                Field currentField = game.getMovedIntoField();
                int currentMoney = currentPlayer.getMoney();

                while (!game.isGameOver()) {
                    game.setNextGameState();
                }

                // Verify player actions and property ownership
                if (currentField.isProperty()) {
                    Property property = (Property) currentField;

                    if (property.getOwner() == null && currentMoney >= COST_OF_UNOWNED_PROPERTY) {
                        // The player should have bought the property
                        assertTrue(currentPlayer.getProperties().contains(property));
                        assertEquals(currentMoney - COST_OF_UNOWNED_PROPERTY, currentPlayer.getMoney());
                        assertEquals(property.getOwner(), currentPlayer);
                    } else if (property.getOwner() != null && !property.getOwner().equals(currentPlayer)) {
                        // The player should have built a house on the property
                        assertTrue(property.hasHouse());
                        assertEquals(currentMoney - COST_OF_BUILDING_A_HOUSE, currentPlayer.getMoney());
                    }
                }
                assertEquals(game.getCurrentTurn(), 2);
            }

            assertTrue(game.isGameOver());
            assertNotNull(game.findWinner());
        } catch (Exception e) {
            fail("Exception occurred during the test: " + e.getMessage());
        }
    }

    @Test
    void testGameResult() {
        CapitalyGame game = new CapitalyGame();
        try {
            game.loadGameParameters("input-2.txt", "roll_dices-2.txt");

            while (!game.isGameOver()) {
                game.setNextGameState();
            }

            String expectedGameResult = "=========! Game Result !=========\n" +
                    "Winner: Careful Player{name='John', money=8300, Number of properties=2}\n" +
                    "Second looser: Greedy Player{name='Mary', money=0, Number of properties=0}\n";

            assertEquals(game.getGameResult(), expectedGameResult);
        } catch (Exception e) {
            fail("Exception occurred during the test: " + e.getMessage());
        }
    }

    @Test
     void testGameParametersLoadedCorrectly() {
        CapitalyGame game = new CapitalyGame();
        try {
            game.loadGameParameters("input-2.txt", "roll_dices-2.txt");
            assertEquals(game.getPlayers().size(), 3); // Verify the number of players
            assertEquals(game.getRolls().size(), 6);   // Verify the number of rolls
            assertEquals(game.getRolls().get(0), 3);   // Verify the first roll value
            assertEquals(game.getRolls().get(5), 5);   // Verify the last roll value
        } catch (Exception e) {
            fail("Exception occurred during the test: " + e.getMessage());
        }
    }
}
