// done

package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;
/**
 * Engine that compute SQRT
 */
public class SQRTEngine implements Computable {
	private static final String engineName ="SQRT";
	
	private double input;
	private double result; 

    
	/**
	 * Setter of Input
	 * @param args Input datas 
	 */
	@Override
	public void setInput(String[] args) { 
		if (args.length == 1)InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 1);
		else if (args.length == 2) {
			Double temp = Double.parseDouble(args[1]); 
			if (temp >= 0) input = temp;  
			else InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
		} else InputChecker.printErrorMesssageForTheNumberOfRequiredInputsAndExit(engineName, 1);
	}
	/**
	 * Setter of Result
	 * @param result Result of compute
	 */
	public void setResult(double result) { this.result = result; }
	
	/**
	 * Compute the engine
	 */
	@Override
	public void compute() { result = Math.sqrt(input); }
	
	/**
	 * Getter of EngineName
	 * @return engineName[string] Name of Engine 
	 */
	public String getEnginName(){ return engineName; }

	/**
	 * Getter of Input
	 * @return input Input data of Number
	 */
	public double getInput(){ return input; }

	/**
	 * Getter of Result
	 * @return result Result of compute 
	 */
	@Override
	public double getResult() { return result; }
}
