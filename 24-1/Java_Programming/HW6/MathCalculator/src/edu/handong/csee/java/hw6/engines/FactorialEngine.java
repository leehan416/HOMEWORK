package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.*;

/**
 * Engine that compute Factorial
 */
public class FactorialEngine implements Computable {
    private static final String engineName = "FACTORIAL";

    private int n;
    private double result = 1;

    /**
     * Setter of Input
     *
     * @param args list of inputs
     */
    @Override
    public void setInput(String[] args) throws MinimumInputNumberException, NegativeNumberException, OneInputException {
        if (args.length < 2) throw new MinimumInputNumberException(engineName, 2);
        else if (args.length == 2) {
            int temp;
            try {
                temp = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                throw new MyNumberFormatException(engineName, args[1]);
            }
            if (0 <= temp) n = temp;
            else throw new NegativeNumberException(engineName);
        } else throw new OneInputException(engineName);
    }

    /**
     * Setter of Result
     *
     * @param result result of factorial
     */
    public void setResult(double result) {
        this.result = result;
    }

    /**
     * Compute Factorial
     */
    @Override
    public void compute() {
        for (int i = 1; i <= n; i++) result *= i;
    }

    /**
     * Getter of Engine Name
     *
     * @return engineName[String]
     */
    public String getEngineName() {
        return engineName;
    }

    /**
     * Getter of N
     *
     * @return n[int]
     */
    public int getN() {
        return n;
    }

    /**
     * Getter of Result
     *
     * @return result[int]
     */
    @Override
    public double getResult() {
        return result;
    }

}