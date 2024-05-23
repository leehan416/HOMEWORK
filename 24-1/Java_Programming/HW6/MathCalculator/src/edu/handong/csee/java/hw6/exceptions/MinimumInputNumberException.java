package edu.handong.csee.java.hw6.exceptions;

/**
 * Class that manage MinimumInputNumberException
 */
public class MinimumInputNumberException extends Exception {

    /**
     * constructor of Exception. <br />set message with parameter
     *
     * @param engineName Name of Engine
     * @param num        Minimum of engine data
     */
    public MinimumInputNumberException(String engineName, int num) {
        super("Exception-02: You need at least " + num + " input values for " + engineName + ".");
    }
}
