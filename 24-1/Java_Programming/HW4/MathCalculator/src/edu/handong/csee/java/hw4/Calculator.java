package edu.handong.csee.java.hw4;

import edu.handong.csee.java.hw4.engines.*;
import edu.handong.csee.java.hw4.util.InputChecker;
/**
 * class for program run
 */
public class Calculator {

	/**
	 * main method on this program
	 * @param args[String]  input the way of calculate and numbers
	*/
	public static void main(String[] args) {

		Calculator myCalculator = new Calculator();
		if (args.length == 0) InputChecker.printErrorMesssageForNoneInputsAndExit();

		myCalculator.run(args);
	}
	/**
	 * run method for this program <br />
	 * it contains the entire of logic of process
	 * @param args Input datas
	 */
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