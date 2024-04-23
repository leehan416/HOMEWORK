
package edu.handong.csee.java.hw4.engines;

import edu.handong.csee.java.hw4.util.InputChecker;

/**
 * Engine that compute Sphere Volume
 */
public class SphereVolEngine implements Computable {
	private static final String engineName ="SPHEREVOL";

	private double radius;
	private double result;
	/**
	 * Setter of Input
	 * @param args[String[]] Input datas 
	 */
	@Override
	public void setInput(String[] args) { 
		if (args.length == 1)InputChecker.printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(engineName, 1);
		else if (args.length == 2){
			double temp = Double.parseDouble(args[1]); 
			if (temp <= 0) InputChecker.printErrorMesssageForNegativeInputsAndExit(engineName);
			else radius = temp;
		} else InputChecker.printErrorMesssageForTheNumberOfRequiredInputsAndExit(engineName, 1);
		

	}
	/**
	 * Setter of result
	 * @param result[double] Reuslt of compute 
	 */
	public void setResult(double result) { this.result = result; }

	/**
	 * compute result 
	 */
	@Override
	public void compute() { result = 4.0/3 * Math.pow(radius, 3)* Math.PI; }

	/**
	 * Getter of Engine name
	 * @return engineName[String] Name of Engine 
	 */
	public String getEnginName(){ return engineName; }


	/**
	 * Getter of Radius
	 * @return radius[double] Data of radius
	 */
	public double getRadius(){ return radius; }

	/**
	 * Getter of Result
	 * @return result[double] result of compute 
	 */
	@Override
	public double getResult() { return result; }
}
