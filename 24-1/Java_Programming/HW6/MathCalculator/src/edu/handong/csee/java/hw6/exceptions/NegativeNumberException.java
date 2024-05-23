package edu.handong.csee.java.hw6.exceptions;

/**
 * Class that manage NegativeNumberException
 */
public class NegativeNumberException extends Exception {

    /**
     * constructor of Exception. <br />set message with parameter
     *
     * @param engineName Name of Engine
     */
    public NegativeNumberException(String engineName) {
        super("Exception-03: The input value cannot be negative for " + engineName + ".");
    }
}
