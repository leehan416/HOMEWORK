//done

package edu.handong.csee.java.hw4.engines;

// import edu.handong.csee.java.hw4.util.InputChecker;

public class FactorialEngine implements Computable {
    private static final String engineName ="FACTORIAL";

    private int n;
    private double result = 1;

    @Override
    public void compute() { for (int i = 1; i <= n; i++) result *=i; }

    @Override
    public void setInput(String[] args) { 
        n = Integer.parseInt(args[1]); 
        // InputChecker.printErrorMesssageForTheNumberOfRequiredInputsAndExit(engineName, 1);    
    }
    
    public String getEngineName(){ return engineName; }
    
    public void setResult(double result){ this.result = result; }
    
    @Override
    public double getResult() { return result; }

    public int getN() { return n; }
}
