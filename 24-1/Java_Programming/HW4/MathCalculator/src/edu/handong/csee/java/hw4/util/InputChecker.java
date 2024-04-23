package edu.handong.csee.java.hw4.util;
/**
 * class for input checker
 */
public class InputChecker {

	/**
	 *  print error messsage that about  number of required <br />
	 *  after print, it ends program
	 * @param engineName[String] Name of Engine
	 * @param numOfRequiredInputs[int] Require of Inputs 
	 */
	public static void printErrorMesssageForTheNumberOfRequiredInputsAndExit(String engineName, int numOfRequiredInputs) {
		System.out.println("You need " + numOfRequiredInputs + " input values for " + engineName.toUpperCase() + ".");
		System.exit(0);
	}
	/**
	 *  print error messsage that about number of minimum required <br />
	 *  after print, it ends program
	 * @param engineName[String] Name of Engine
	 * @param numOfMinimumRequiredInputs[int] Minimun of Inputs 
	 */
	public static void printErrorMessageForTheNumberOfMinimumRequiredInputsAndExit(String engineName, int numOfMinimumRequiredInputs){
		System.out.println("You need at least " + numOfMinimumRequiredInputs + " input values for " + engineName.toUpperCase() + ".");
		System.exit(0);
	}
	/**
	 *  print error messsage that about negative number <br />
	 *  after print, it ends program
	 * @param engineName[String] Name of Engine
	 */
	public static void printErrorMesssageForNegativeInputsAndExit(String engineName){
		System.out.println("The input value cannot be negative for " + engineName.toUpperCase() + ".");
		System.exit(0);
	}	

	/**
	 *  print error messsage that about None value <br />
	 *  after print, it ends program
	 */
	public static void printErrorMesssageForNoneInputsAndExit(){
		System.out.println(
			"Please put a computing engine option such as LCM, GCD, SQRT, FACTORIAL, FIBONACCI, MAX, MIN, CUBEVOL, and SPHEREVOL.\nFor example, java -cp [your classpath] edu.handong.csee.java.hw4.Calculator MAX 12 4 5 45 100 "
			);
		System.exit(0);
	}

}
