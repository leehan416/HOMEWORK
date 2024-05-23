package edu.handong.csee.java.hw6.exceptions;

/**
 * Class that manage InvalidCommandException
 */
public class InvalidCommandException extends Exception {

    /**
     * constructor of Exception. <br />set message with parameter
     * @param command Wrong command that user input
     */
    public InvalidCommandException(String command) {
        super("Exception-01: Invalid command: " + command + "\nPlease put a computing engine option such as LCM, GCD, SQRT, FACTORIAL, FIBONACCI, " +
                "MAX, MIN, CUBEVOL, and SPHEREVOL. For example, ./app  MAX 12 4 5 45 100");
    }
}
