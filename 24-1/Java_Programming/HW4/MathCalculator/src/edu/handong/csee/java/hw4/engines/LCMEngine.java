package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;

/**
 *  Engine that compute LCM
 */
public class LCMEngine implements Computable{
	private static final String engineName ="LCM";

	private int[] input;
	
	private int result;
	
	/**
	 * Setter of Input
	 * @param args[String[]] Input datas 
	 */
	@Override
	public void setInput(String[] args) {
		if (3 <= args.length) {
			input =new int[args.length-1];
			for (int i = 1; i < args.length; i++) {
				int temp =  Integer.parseInt(args[i]);
				if (temp <= 0) InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
				else input[i-1] = temp;
			}
		} else InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 2);
	}

	/**
	 * Setter of Result 
	 * @param result Result of compute
	 */
	public void setResult(int result){ this.result = result; }
	
	/**
	 * compute LCM
	 */
	@Override
	public void compute() {
		int max = Integer.MIN_VALUE;
		//find max value
		for (int i : input)  if (i > max) max = i;

		for (int i = 1;; i++){
			int temp = i * max; // curr value
			int check = 0;
			
			for (int j: input) // find it is valid 
				if (temp % j == 0) check ++;
			
			if (check == input.length) {
				result = temp;
				break;
			}
		}
	}

	/**
	 * Getter of Engine Name
	 * @return engineName[String] Name of Engine 
	 */
	public String getEngineName(){ return engineName; }

	/**
	 * Getter of input
	 * @return input[int[]] Input datas of number
	 */
	public int[] getInput(){ return input;}

	/**
	 * Getter of Result
	 * @return result[double] Result of compute
	 */
	@Override
	public double getResult() { return result; }
}
