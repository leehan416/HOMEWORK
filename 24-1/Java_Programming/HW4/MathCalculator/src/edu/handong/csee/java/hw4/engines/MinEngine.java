package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;

/**
 * Engine that find Min value
 */
public class MinEngine implements Computable {
	private static final String engineName ="MIN";

	private double[] input;
	private double result;
	
	/**
	 * Setter of Input
	 * @param args[String[]] Input datas 
	 */
	@Override
	public void setInput(String[] args) {
		if (args.length < 3) InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 2);
		else {
			input = new double[args.length];
			for (int i = 1; i < args.length; i++)
				input[i] = Double.parseDouble(args[i]);
		}
	}

	/**
	 * Setter of Result
	 * @param result[double] Result of compute 
	 */
	public void setResult(double result) {
		this.result = result;
	}

	/**
	 * find Min Value
	 */
	@Override
	public void compute() {
		double min = 9999999999999999.0;
		for (int i = 1; i < input.length; i++)
			if (input[i] <= min) min = input[i];
		result = min;
	}
	
	/**
	 * Setter of Engine Name
	 * @return engineName[String] Name of Engine
	 */
	public String getEnginName(){ return engineName; }
	

	/**
	 * Getter of Input
	 * @return input[double[]] Input datas of number
	 */
	public double[] getInput(){ return input; }

	/**
	 * Getter of Result
	 * @return result[double] Result of compute
	 */
	@Override
	public double getResult() { return result; }
}
