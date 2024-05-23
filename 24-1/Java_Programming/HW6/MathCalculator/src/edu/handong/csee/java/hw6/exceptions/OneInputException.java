package edu.handong.csee.java.hw6.exceptions;

/**
 * Class that manage OneInputException
 */
public class OneInputException extends Exception {

    /**
     * constructor of Exception. <br />set message with parameter
     *
     * @param engineName Name of Engine
     */
    public OneInputException(String engineName) {
        super("Exception-04: You need one input value for " + engineName + ".");
    }
}
