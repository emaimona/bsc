package game;

import field.Field;
import player.Player;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import static java.text.MessageFormat.format;
import static util.CustomFileReader.readInputGameFromFile;
import static util.CustomFileReader.readRollDiceFromFile;

public class CapitalyGame {
    private List<Player> players = new ArrayList<>();
    private List<Field> board = new ArrayList<>();
    private List<Integer> rolls = new ArrayList<>();
    private int currentTurn = 0;
    private int currentDiceRoll = 0;
    private int numberOfLosers = 0;

    public List<Player> getPlayers() {
        return players;
    }

    public void addNewPlayer(Player player) {
        this.players.add(player);
    }

    public int getCurrentTurn() {
        return currentTurn;
    }

    public List<Integer> getRolls() {
        return rolls;
    }

    /**
     * Add a new field to the board
     * @param field
     */
    public void addNewFieldToTheBoard(Field field) {
        this.board.add(field);
    }

    /**
     * Load the game parameters from the input files
     * @param inputFileName
     * @param rollDiceFileName
     * @throws Exception
     */
    public void loadGameParameters(String inputFileName, String rollDiceFileName) throws Exception {
       readInputGameFromFile(this, inputFileName);
       readRollDiceFromFile(this, rollDiceFileName);
    }

    /**
     * Check if the game is over
     * @return true if the game is over, false otherwise
     */
    public boolean isGameOver() {
        return numberOfLosers >= (players.size() - 1);
    }

    /**
     * Get the second looser of the game
     * @return Player
     */
    public Player findSecondLoser() {
        if (!isGameOver())
            return null;
        return players.stream()
                .sorted(Comparator.comparing(Player::getMoney))
                .skip(1)
                .findFirst()
                .orElse(null);
    }

    /**
     * Get the winner of the game
     * @return Player
     */
    public Player findWinner() {
        if (!isGameOver())
            return null;
        return players.stream()
                .sorted(Comparator.comparing(Player::getMoney).reversed())
                .findFirst()
                .orElse(null);
    }

    /**
     * Process the player's turn
     * @param player
     * @param field
     */
    private void processPlayerTurn(Player player, Field field) {
        player.applyStrategy(field);
    }

    /**
     * Set the next turn, and skip the bankrupt players
     */
    public void setNextTurn() {
        currentTurn = (currentTurn + 1) % players.size();
        if (getCurrentPlayer().isBankrupt())
            setNextTurn();
    }

    /**
     * Get the current player
     * @return Player
     */
    public Player getCurrentPlayer() {
        return players.get(currentTurn);
    }

    /**
     * Get the rolled dice value for the field
     * @return int
     */
    public int getRolledDiceValue() {
        return rolls.get(currentDiceRoll) % board.size();
    }

    /**
     * Set the next dice roll
     */
    public void setNextDiceRoll() {
        currentDiceRoll = (currentDiceRoll + 1) % rolls.size();
    }

    /**
     * Add a new roll to the list of rolls
     */
    public void addNewRoll(int roll) {
        this.rolls.add(roll);
    }

    /**
     * Get the field the player moved into
     * @return Field
     */
    public Field getMovedIntoField() {
        return board.get(getRolledDiceValue());
    }

    /**
     * Set the game state to the next turn
     */
    public void setNextGameState() {
        setNextTurn();
        setNextDiceRoll();
        processPlayerTurn(getCurrentPlayer(), getMovedIntoField());
        handleLoser(getCurrentPlayer());
    }

    /**
     * Check if the player is bankrupt, and update the looser count
     */
    private void handleLoser(Player player) {
        if (player.isBankrupt())
            numberOfLosers++;
    }

    /**
     * Get the game state
     * @return String
     */
    public String getGameState() {
        return format("Current turn: {0}\nCurrent Player: {1}\nDice rolled: {2}\n", getCurrentTurn(), getCurrentPlayer(), getRolledDiceValue());
    }

    /**
     * Get the game result, if the game is over
     * @return String
     */
    public String getGameResult() {
        if (!isGameOver())
            return "Game is not over yet!";
        return format("=========! Game Result !=========\nWinner: {0}\nSecond looser: {1}\n", findWinner(), findSecondLoser());
    }
}
