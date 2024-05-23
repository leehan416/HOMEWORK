package edu.handong.csee.java.hw6.exceptions;

/**
 * Class that manage MyNumberFormatException
 */
public class MyNumberFormatException extends NumberFormatException {

    /**
     * constructor of Exception. <br />set message with parameter
     * @param engineName Name of Engine
     * @param input Wrong input data
     */
    public MyNumberFormatException(String engineName, String input) {
        super("Exception-05: The input value should be converted into a number. " +
                "(" + input + " is not a number value for " + engineName + ".)");
    }
}
