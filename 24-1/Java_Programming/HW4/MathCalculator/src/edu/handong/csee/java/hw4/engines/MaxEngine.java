//done

package edu.handong.csee.java.hw4.engines;

public class MaxEngine implements Computable {
    private static final String engineName ="MAX";

    double[] input;
    double result=0;

    @Override
    public void setInput(String[] args) { 
        input = new double[args.length];
        for (int i = 1; i < args.length; i++)
            input[i] = Double.parseDouble(args[i]);
    }

    public void setResult(double result) { this.result = result; }
    
    @Override
    public void compute() {
        double max = Double.MIN_VALUE;
        for (double i : input)
            if (i > max) max = i;
        result = max;
    }

    public String getEnginName(){ return engineName; }

    public double[] getInput(){ return input; }

    @Override
    public double getResult(){ return result; }
}