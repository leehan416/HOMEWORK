package edu.handong.csee.java.hw4.engines;

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
	 * @param args[String[]] Input datas 
	 */
	void setInput(String[] args);

	/**
	 * method that get Result(getter of Result data)
	 * @return result[double] Result of compute
	 */
	double getResult();
}
