package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.MyNumberFormatException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;
import edu.handong.csee.java.hw6.exceptions.OneInputException;

/**
 * Engine that compute Cube volume
 */
public class CubeVolEngine implements Computable {
    private static final String engineName = "CUBEVOL";

    private double sideLength;
    private double volume;

    /**
     * Setter of Input
     *
     * @param args Input datas
     */
    @Override
    public void setInput(String[] args) throws NegativeNumberException, MinimumInputNumberException, MyNumberFormatException, OneInputException {
        if (args.length == 1) throw new MinimumInputNumberException(engineName, 1);
        else if (args.length == 2) {
            double temp;
            try {
                temp = Double.parseDouble(args[1]);
            } catch (NumberFormatException e) {
                throw new MyNumberFormatException(engineName, args[1]);
            }
            if (0 <= temp) sideLength = temp;
            else throw new NegativeNumberException(engineName);
        } else throw new OneInputException(engineName);
    }

    /**
     * Setter of Volume
     *
     * @param volume Volume(result) of input data
     */
    public void setVolume(double volume) {
        this.volume = volume;
    }

    /**
     * Compute cube volume
     */
    @Override
    public void compute() {
        volume = Math.pow(sideLength, 3);
    }

    /**
     * Getter of Engine Name
     *
     * @return engineName Name of Enigine
     */
    public String getEnginName() {
        return engineName;
    }

    /**
     * Getter of SideLength
     *
     * @return sideLength Input data of number
     */
    public double getSideLength() {
        return sideLength;
    }

    /**
     * Getter of Result
     *
     * @return volume[double] Volume(result) of input data
     */
    @Override
    public double getResult() {
        return volume;
    }

}