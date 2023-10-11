import game.CapitalyGame;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Welcome to the game ===\n");
        CapitalyGame game = new CapitalyGame();
        try {
            game.loadGameParameters("input-1.txt", "roll_dices-1.txt");
            System.out.println("Dices: " + game.getRolls());
            System.out.println("Initial status for players: " + game.getPlayers());
            System.out.println();

            while (!game.isGameOver()) {
                game.setNextGameState();
                System.out.println(game.getGameState());
            }

            System.out.println("Final status for players: " + game.getPlayers());
            System.out.println();
            System.out.println(game.getGameResult());

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
