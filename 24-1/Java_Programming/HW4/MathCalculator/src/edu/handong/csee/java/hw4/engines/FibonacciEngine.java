package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;

/**
 * Engine that compute Fibonacci
 */
public class FibonacciEngine implements Computable {
	private static final String engineName ="FIBONACCI";

	private int n;
	private double result;
	
	/**
	 * Setter of Input
	 * @param args[String[]] Input datas 
	 */
	@Override
	public void setInput(String[] args) {
		if (args.length < 2) InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 1);
		else if (args.length == 2){
			int temp = Integer.parseInt(args[1]);
			if(0 <=  temp) n  = temp;
			else InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
		} else InputChecker.printErrorMesssageForTheNumberOfRequiredInputsAndExit(engineName, 1);
	}

	/**
	 * Setter of Result
	 * @param result[double] Result of compute
	 */
	public void setResult(double result){ this.result = result; }
	
	/**
	 * compute Fibonacci Number
	 */
	@Override
	public void compute() {
		int a1 = 1;
		int a2 = 1;
		result = 1;
		if(n <= 2) return;
		for (int i = 2; i < n; i++) {
			int temp = a1 + a2;
			a2 = a1;
			a1 = temp;
			result = temp;
		}
	}

	/**
	 * Getter of Engine Name
	 * @return engineName[String] Name of Engine
	 */
	public String getEnginName(){ return engineName; }

	/**
	 * Getter of N
	 * @return n[int] Input datas of numbers
	 */
	public int getN() { return n; }
	
	/**
	 * Getter of Result
	 * @return result[double] Result of compute
	 */
	@Override 
	public double getResult() { return result; }

}
