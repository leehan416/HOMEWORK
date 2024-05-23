package edu.handong.csee.java.hw6;

import edu.handong.csee.java.hw6.engines.*;
import edu.handong.csee.java.hw6.exceptions.*;

/**
 * class for program run
 */
public class Calculator {

    /**
     * main method on this program
     *
     * @param args input the way of calculate and numbers
     */
    public static void main(String[] args) {
        Calculator myCalculator = new Calculator();
        myCalculator.run(args);
    }

    /**
     * run method for this program <br />
     * it contains the entire of logic of process
     *
     * @param args Input datas
     */
    public void run(String[] args) {

        try {
            if (args.length == 0) throw new InvalidCommandException("");
            String engineName = args[0].toUpperCase();

            Computable engine = null;
            switch (engineName) {
                case "LCM":
                    engine = new LCMEngine();
                    break;
                case "GCD":
                    engine = new GCDEngine();
                    break;
                case "SQRT":
                    engine = new SQRTEngine();
                    break;
                case "FACTORIAL":
                    engine = new FactorialEngine();
                    break;
                case "FIBONACCI":
                    engine = new FibonacciEngine();
                    break;
                case "MAX":
                    engine = new MaxEngine();
                    break;
                case "MIN":
                    engine = new MinEngine();
                    break;
                case "CUBEVOL":
                    engine = new CubeVolEngine();
                    break;
                case "SPHEREVOL":
                    engine = new SphereVolEngine();
                    break;
                default:
                    throw new InvalidCommandException(engineName);
            }
            engine.setInput(args);
            engine.compute();
            System.out.println("The result of " + engineName + " is " + engine.getResult() + ".");

        } catch (InvalidCommandException e) {
            System.out.println(e.getMessage());
        } catch (MinimumInputNumberException e) {
            System.out.println(e.getMessage());
        } catch (NegativeNumberException e) {
            System.out.println(e.getMessage());
        } catch (OneInputException e) {
            System.out.println(e.getMessage());
        } catch (MyNumberFormatException e) {
            System.out.println(e.getMessage());
        }
        System.exit(0);
    }
}