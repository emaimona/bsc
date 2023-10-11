import exception.InvalidStrategyException;
import field.Property;
import org.junit.jupiter.api.Test;
import player.Careful;
import player.Greedy;
import player.Player;
import player.Tactical;
import util.CustomFunctions;

import static org.junit.jupiter.api.Assertions.*;

class CapitalyGameWhiteBoxTest {

    @Test
    void testBuyPropertyWithPlayer() {
        Player player = new Greedy("TestPlayer");
        Property property = new Property();

        player.buyProperty(property);

        assertTrue(player.getProperties().contains(property));
        assertEquals(player.getMoney(), 9000);
        assertEquals(property.getOwner(), player);
    }

    @Test
    void testPayOwner() {
        Player player1 = new Careful("Player1");
        Player player2 = new Greedy("Player2");
        Property property = new Property();

        property.setOwner(player2);

        player1.payOwner(player2, 500);

        assertEquals(player1.getMoney(), 9500);
        assertEquals(player2.getMoney(), 10500);
    }

    @Test
    void testIsBankrupt() {
        Player player = new Tactical("TestPlayer");
        assertFalse(player.isBankrupt());
    }

    @Test
    void testGetNewPlayerWithValidStrategies() throws InvalidStrategyException {
        Player player1 = CustomFunctions.getNewPlayer("Player1", "Greedy");
        Player player2 = CustomFunctions.getNewPlayer("Player2", "Careful");
        Player player3 = CustomFunctions.getNewPlayer("Player3", "Tactical");

        assertTrue(player1 instanceof Greedy);
        assertTrue(player2 instanceof Careful);
        assertTrue(player3 instanceof Tactical);

        assertEquals(player1.getName(), "Player1");
        assertEquals(player2.getName(), "Player2");
        assertEquals(player3.getName(), "Player3");
    }

    @Test
     void testGetNewPlayerWithInvalidStrategy() {
        assertThrows(InvalidStrategyException.class, () -> {
            CustomFunctions.getNewPlayer("InvalidPlayer", "InvalidStrategy");
        });
    }
}
