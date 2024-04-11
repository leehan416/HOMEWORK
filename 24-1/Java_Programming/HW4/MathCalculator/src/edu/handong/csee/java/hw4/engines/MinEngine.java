//done

package edu.handong.csee.java.hw4.engines;

// import java.util.Arrays;

public class MinEngine implements Computable {
    private static final String engineName ="MIN";

    private double[] input;
    private double result;
    
    @Override
    public void setInput(String[] args) {
        input = new double[args.length];
        for (int i = 1; i < args.length; i++)
            input[i] = Double.parseDouble(args[i]);
    }
    public void setResult(double result) {
        this.result = result;
    }

    @Override
    public void compute() {
        double min = 9999999999999999.0;
        // for (double i : input)
        for (int i = 1; i < input.length; i++)
            if (input[i] <= min) min = input[i];
        result = min;
    }
    
    public String getEnginName(){ return engineName; }
    
    public double[] getInput(){ return input; }
    
    @Override
    public double getResult() { return result; }
    

}
