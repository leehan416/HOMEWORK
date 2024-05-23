
package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.MyNumberFormatException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;
import edu.handong.csee.java.hw6.exceptions.OneInputException;

/**
 * Engine that compute Sphere Volume
 */
public class SphereVolEngine implements Computable {
    private static final String engineName = "SPHEREVOL";

    private double radius;
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
            if (temp <= 0) throw new NegativeNumberException(engineName);
            else radius = temp;
        } else throw new OneInputException(engineName);
    }

    /**
     * Setter of result
     *
     * @param result Reuslt of compute
     */
    public void setResult(double result) {
        this.result = result;
    }

    /**
     * compute result
     */
    @Override
    public void compute() {
        result = 4.0 / 3 * Math.pow(radius, 3) * Math.PI;
    }

    /**
     * Getter of Engine name
     *
     * @return engineName Name of Engine
     */
    public String getEnginName() {
        return engineName;
    }


    /**
     * Getter of Radius
     *
     * @return radius Data of radius
     */
    public double getRadius() {
        return radius;
    }

    /**
     * Getter of Result
     *
     * @return result result of compute
     */
    @Override
    public double getResult() {
        return result;
    }
}
