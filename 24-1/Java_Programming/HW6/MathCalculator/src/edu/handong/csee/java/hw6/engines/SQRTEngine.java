// done

package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.*;

/**
 * Engine that compute SQRT
 */
public class SQRTEngine implements Computable {
    private static final String engineName = "SQRT";

    private double input;
    private double result;


    /**
     * Setter of Input
     *
     * @param args Input datas
     */
    @Override
    public void setInput(String[] args) throws MyNumberFormatException, MinimumInputNumberException, NegativeNumberException, OneInputException {
        if (args.length == 1) throw new MinimumInputNumberException(engineName, 1);
        else if (args.length == 2) {
            double temp;
            try {
                temp = Double.parseDouble(args[1]);
            } catch (NumberFormatException e) {
                throw new MyNumberFormatException(engineName, args[1]);
            }
            if (temp >= 0) input = temp;
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
     * Compute the engine
     */
    @Override
    public void compute() {
        result = Math.sqrt(input);
    }

    /**
     * Getter of EngineName
     *
     * @return engineName Name of Engine
     */
    public String getEnginName() {
        return engineName;
    }

    /**
     * Getter of Input
     *
     * @return input Input data of Number
     */
    public double getInput() {
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
