package edu.handong.csee.java.hw6.engines;

import edu.handong.csee.java.hw6.exceptions.MinimumInputNumberException;
import edu.handong.csee.java.hw6.exceptions.NegativeNumberException;
import edu.handong.csee.java.hw6.exceptions.OneInputException;

/**
 *  Interface for each engines
 */
public interface Computable {
	/**
	 * method that compute on each engines 
	 */
	void compute();

	/**
	 * method that set Inputs(setter of Input data)
	 * @param args Input datas
	 */
	void setInput(String[] args) throws MinimumInputNumberException, NegativeNumberException, OneInputException;

	/**
	 * method that get Result(getter of Result data)
	 * @return result Result of compute
	 */
	double getResult();
}
