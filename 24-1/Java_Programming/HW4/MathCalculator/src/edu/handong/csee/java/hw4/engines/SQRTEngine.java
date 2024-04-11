// done

package edu.handong.csee.java.hw4.engines;

// import edu.handong.csee.java.hw4.util.InputChecker;

public class SQRTEngine implements Computable {
    private static final String engineName ="SQRT";

    private double input;
    
    private double result; 
    
    @Override
    public void setInput(String[] args) { input = Double.parseDouble(args[1]); System.out.println(input); }

    public void setResult(double result) { this.result = result; }
    
    @Override
    public void compute() { result = Math.sqrt(result); }


    public String getEnginName(){ return engineName; }


    public double getInput(){ return input; }

    @Override
    public double getResult() { return result; }

}
