package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;
/**
 * Engine that compute Factorial
 */
public class FactorialEngine implements Computable {
	private static final String engineName ="FACTORIAL";

	private int n;
	private double result = 1;

	/**
	 * Setter of Input
	 * @param args[String[]]
	 */
	@Override
	public void setInput(String[] args) { 
		if (args.length < 2) InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 1);
		else if (args.length ==2) {
			int temp =  Integer.parseInt(args[1]); 
			if (0 <= temp) n = temp;
			else InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
		} else InputChecker.printErrorMesssageForTheNumberOfRequiredInputsAndExit(engineName, 1);    
	}
	
	/**
	 * Setter of Result
	 * @param result[double]
	 */
	public void setResult(double result){ this.result = result; }
	
	/**
	 * Compute Factorial
	 */
	@Override
	public void compute() { for (int i = 1; i <= n; i++) result *= i; }

	/**
	 * Getter of Engine Name
	 * @return engineName[String]
	 */
	public String getEngineName(){ return engineName; }


	/**
	 * Getter of N
	 * @return n[int]
	 */
	public int getN() { return n; }
	/**
	 * Getter of Result
	 * @return result[int]
	 */
	@Override
	public double getResult() { return result; }

}