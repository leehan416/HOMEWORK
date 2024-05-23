package edu.handong.csee.java.hw6.engines;


import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.MyNumberFormatException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;

/**
 * Engine that find Min value
 */
public class MinEngine implements Computable {
    private static final String engineName = "MIN";

    private double[] input;
    private double result;

    /**
     * Setter of Input
     *
     * @param args Input datas
     */

    @Override
    public void setInput(String[] args) throws NegativeNumberException, MinimumInputNumberException, MyNumberFormatException {
        if (args.length < 3) throw new MinimumInputNumberException(engineName, 2);
        else {
            input = new double[args.length];
            for (int i = 1; i < args.length; i++) {
                try {
                    input[i] = Double.parseDouble(args[i]);
                } catch (NumberFormatException e) {
                    throw new MyNumberFormatException(engineName, args[i]);
                }
            }
        }
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
     * find Min Value
     */
    @Override
    public void compute() {
        double min = Double.MAX_VALUE;
        for (int i = 1; i < input.length; i++)
            if (input[i] <= min) min = input[i];
        result = min;
    }

    /**
     * Setter of Engine Name
     *
     * @return engineName Name of Engine
     */
    public String getEnginName() {
        return engineName;
    }


    /**
     * Getter of Input
     *
     * @return input Input datas of number
     */
    public double[] getInput() {
        return input;
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
