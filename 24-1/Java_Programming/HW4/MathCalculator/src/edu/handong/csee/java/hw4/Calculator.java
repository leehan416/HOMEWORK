package edu.handong.csee.java.hw4;

import edu.handong.csee.java.hw4.engines.*;

public class Calculator {

    public static void main(String[] args) {

        Calculator myCalculator = new Calculator();

        myCalculator.run(args);
    }

    public void run(String[] args) {

        String engineName = args[0].toUpperCase();

        Computable engine = null;

        switch(engineName) {
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
                System.out.println("Invalid command: " + engineName);
                System.exit(0);
        }

        engine.setInput(args);
        engine.compute();
        System.out.println("The result of " +  engineName + " is " + engine.getResult() + ".");
    }
}