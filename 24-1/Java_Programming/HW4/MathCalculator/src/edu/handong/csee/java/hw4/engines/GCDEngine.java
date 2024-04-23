package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;

/**
 * Engine that compute GCD
 */
public class GCDEngine implements Computable {
	private static final String engineName = "GCD";

	private int[] input;
	private int result;

	/**
	 * Setter of Input
	 * @param args[String[]] Input datas
	 */
	@Override
	public void setInput(String[] args) { 
		if (args.length < 3) InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 2);
		else if (3  <= args.length) {
			input = new int[args.length-1];
			for (int i  = 1; i < args.length; i++){
				int temp = Integer.parseInt(args[i]);
				if (0 <= temp) input[i-1] = temp;
				else InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
			}
		}
	}

	/**
	 * Setter of Result
	 * @param result[int] to change data result of compute
	 */
	public void setResult(int result){ this.result =result; }

	/**
	 * compute GCD
	 */
	@Override
	public void compute() {
		result = 1;
		int min = Integer.MAX_VALUE;
		//find min value
		for (int i : input)  if (min > i) min = i;
		
		for (int i = 1; i <= min; i++){
			int check = 0;
			for (int j: input)
				if (j % i == 0) check ++;
			if (check == input.length) result = i;
		}
	}

	/**
	 * getter of EngineName
	 * @return engineName[String] name of Engine
	 */
	public String getEnginName(){ return engineName; }
	
	/**
	 * Getter of Input
	 * @return input[int[]] Inputs of number data
	 */
	public int[] getInput() {return input;}

	/**
	 * Getter of Result
	 * @return result[double] Result of compute
	 */
	@Override
	public double getResult() { return result; }
}
