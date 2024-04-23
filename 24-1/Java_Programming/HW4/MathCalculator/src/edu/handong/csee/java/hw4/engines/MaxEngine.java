package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;

/**
 * Engine that find Min value
 */
public class MaxEngine implements Computable {
	private static final String engineName ="MAX";

	private double[] input;
	private double result = 0;

	/**
	 * Setter of Input
	 * @param args[String] Input datas 
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
	 * Setter of Reuslt
	 * @param result[dobule] Reuslt of compute 
	 */
	public void setResult(double result) { this.result = result; }
	
	/**
	 * find Max Value
	 */
	@Override
	public void compute() {
		double max = Double.MIN_VALUE;
		for (double i : input)
			if (i > max) max = i;
		result = max;
	}
	/**
	 * Getter of Engine Name
	 * @return engineName[String] Name of Engine
	 */
	public String getEnginName(){ return engineName; }

	/**
	 * Getter of Input
	 * @return input[double[]] Input datas of Number
	 */
	public double[] getInput(){ return input; }

	/**
	 * Getter of Result
	 * @return result[double] Result of compute
	 */
	@Override
	public double getResult(){ return result; }
}