package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.MyNumberFormatException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;
import edu.handong.csee.java.hw6.exceptions.OneInputException;

/**
 * Engine that compute Fibonacci
 */
public class FibonacciEngine implements Computable {
    private static final String engineName = "FIBONACCI";

    private int n;
    private double result;

    /**
     * Setter of Input
     *
     * @param args list of  Input datas
     */
    @Override
    public void setInput(String[] args) throws NegativeNumberException, MinimumInputNumberException, MyNumberFormatException, OneInputException {
        if (args.length < 2) throw new MinimumInputNumberException(engineName, 1);
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
     * @param result Result of compute
     */
    public void setResult(double result) {
        this.result = result;
    }

    /**
     * compute Fibonacci Number
     */
    @Override
    public void compute() {
        int a1 = 1;
        int a2 = 1;
        result = 1;
        if (n <= 2) return;
        for (int i = 2; i < n; i++) {
            int temp = a1 + a2;
            a2 = a1;
            a1 = temp;
            result = temp;
        }
    }

    /**
     * Getter of Engine Name
     *
     * @return engineName Name of Engine
     */
    public String getEnginName() {
        return engineName;
    }

    /**
     * Getter of N
     *
     * @return n Input datas of numbers
     */
    public int getN() {
        return n;
    }

    /**
     * Getter of Result
     *
     * @return result Result of compute
     */
    @Override
    public double getResult() {
        return result;
    }

}
