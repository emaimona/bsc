package util;

import exception.WrongFileFormat;
import field.Lucky;
import field.Property;
import field.Service;
import game.CapitalyGame;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

import static util.CustomFunctions.getNewPlayer;

public class CustomFileReader {
    private static final String ROOT_DIRECTORY = "src/main/resources/";
    private CustomFileReader() {}

    /**
     * Read the rolls from the file
     * @param capitalyGame
     * @param filename
     * @throws FileNotFoundException, WrongFileFormat, Exception
     */
    public static void readRollDiceFromFile(CapitalyGame capitalyGame, String filename) throws Exception{
        try(BufferedReader br = new BufferedReader(new FileReader(ROOT_DIRECTORY + filename))) {
            br.lines().forEach(line -> {
                capitalyGame.addNewRoll(Integer.parseInt(line));
            });
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException("The file does not exist");
        } catch (Exception e) {
            throw new WrongFileFormat("Wrong file format");
        }
    }

    /**
     * Read the game parameters from the file
     * @param capitalyGame
     * @param filename
     * @throws FileNotFoundException, WrongFileFormat, Exception
     */
    public static void readInputGameFromFile(CapitalyGame capitalyGame, String filename) throws Exception {
        try(BufferedReader br = new BufferedReader(new FileReader(ROOT_DIRECTORY + filename))) {
            int numberOfFields = Integer.parseInt(br.readLine());
            if (numberOfFields < 0)
                throw new WrongFileFormat("Wrong number of fields");

            while (numberOfFields > 0) {
                String line = br.readLine();
                String[] field = line.split(" ");
                if (field[0].equals("Service")) {
                    capitalyGame.addNewFieldToTheBoard(new Service(Integer.parseInt(field[1])));
                } else if (field[0].equals("Property")) {
                    capitalyGame.addNewFieldToTheBoard(new Property());
                } else if (field[0].equals("Lucky")) {
                    capitalyGame.addNewFieldToTheBoard(new Lucky(Integer.parseInt(field[1])));
                }
                numberOfFields--;
            }
            int numberOfPlayers = Integer.parseInt(br.readLine());
            if (numberOfPlayers < 2)
                throw new WrongFileFormat("Wrong number of players");

            while (numberOfPlayers > 0) {
                String line = br.readLine();
                String[] attributes = line.split(" ");
                capitalyGame.addNewPlayer(getNewPlayer(attributes[0], attributes[1]));
                numberOfPlayers--;
            }

        } catch (FileNotFoundException e) {
            throw new FileNotFoundException("The file does not exist");
        } catch (Exception e) {
            throw new WrongFileFormat("Wrong file format");
        }
    }
}
