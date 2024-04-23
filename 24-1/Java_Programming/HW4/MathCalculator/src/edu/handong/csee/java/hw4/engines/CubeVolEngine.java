package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;
/**
 * Engine that compute Cube volume
 */
public class CubeVolEngine implements Computable {
	private static final String engineName = "CUBEVOL";

	private double sideLength;
	private double volume;

	/**
	 * Setter of Input
	 * @param args[String[]] Input datas 
	 */
	@Override
	public void setInput(String[] args) { 

		if (args.length  == 1) InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 1);
		else if(args.length  == 2) {
			double temp = Double.parseDouble(args[1]); 
			if (0 <= temp) sideLength = temp;
			else InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
		}
		else InputChecker.printErrorMesssageForTheNumberOfRequiredInputsAndExit(engineName, 1);
	}
	/**
	 * Setter of Volume
	 * @param volume[dobule] Volume(result) of input data
	 */
	public void setVolume(double volume) { this.volume = volume; }
	
	/**
	 * Compute cube volume
	 */
	@Override
	public void compute() { volume = Math.pow(sideLength, 3); }

	/**
	 * Getter of Engine Name
	 * @return engineName[String] Name of Enigine
	 */
	public String getEnginName() { return engineName; }

	/**
	 * Getter of SideLength
	 * @return sideLength[double] Input data of number
	 */
 	public double getSideLength() { return sideLength; }

	/**
	 * Getter of Result
	 * @return volume[double] Volume(result) of input data
	 */
 	@Override
 	public double getResult() { return volume; }

}