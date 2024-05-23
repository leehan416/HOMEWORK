package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.MyNumberFormatException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;

/**
 * Engine that compute GCD
 */
public class GCDEngine implements Computable {
    private static final String engineName = "GCD";

    private int[] input;
    private int result;

    /**
     * Setter of Input
     *
     * @param args Input datas
     */
    @Override
    public void setInput(String[] args) throws NegativeNumberException, MinimumInputNumberException, MyNumberFormatException {
        if (args.length < 3) throw new MinimumInputNumberException(engineName, 2);
        else if (3 <= args.length) {
            input = new int[args.length - 1];
            for (int i = 1; i < args.length; i++) {
                int temp;
                try {
                    temp = Integer.parseInt(args[i]);
                } catch (NumberFormatException e) {
                    throw new MyNumberFormatException(engineName, args[i]);
                }
                if (0 <= temp) input[i - 1] = temp;
                else throw new NegativeNumberException(engineName);
            }
        }
    }

    /**
     * Setter of Result
     *
     * @param result to change data result of compute
     */
    public void setResult(int result) {
        this.result = result;
    }

    /**
     * compute GCD
     */
    @Override
    public void compute() {
        result = 1;
        int min = Integer.MAX_VALUE;
        //find min value
        for (int i : input) if (min > i) min = i;

        for (int i = 1; i <= min; i++) {
            int check = 0;
            for (int j : input)
                if (j % i == 0) check++;
            if (check == input.length) result = i;
        }
    }

    /**
     * getter of EngineName
     *
     * @return engineName name of Engine
     */
    public String getEnginName() {
        return engineName;
    }

    /**
     * Getter of Input
     *
     * @return input List of inputs that number data
     */
    public int[] getInput() {
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
