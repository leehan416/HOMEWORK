package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.MyNumberFormatException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;

/**
 * Engine that find Min value
 */
public class MaxEngine implements Computable {
    private static final String engineName = "MAX";

    private double[] input;
    private double result = 0;

    /**
     * Setter of Input
     *
     * @param args Input datas
     */
    @Override
    public void setInput(String[] args) throws NegativeNumberException, MinimumInputNumberException, MyNumberFormatException {
        if (args.length < 3) throw new MinimumInputNumberException(engineName, 2);
        else {
            input = new double[args.length - 1];
            for (int i = 1; i < args.length; i++) {
                try {
                    input[i - 1] = Double.parseDouble(args[i]);
                } catch (NumberFormatException e) {
                    throw new MyNumberFormatException(engineName, args[i]);
                }
            }

        }
    }


    /**
     * Setter of Reuslt
     *
     * @param result Reuslt of compute
     */
    public void setResult(double result) {
        this.result = result;
    }

    /**
     * find Max Value
     */
    @Override
    public void compute() {
        double max = Double.MIN_VALUE;
        for (double i : input)
            if (i > max) max = i;
        result = max;
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
     * Getter of Input
     *
     * @return input Input datas of Number
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