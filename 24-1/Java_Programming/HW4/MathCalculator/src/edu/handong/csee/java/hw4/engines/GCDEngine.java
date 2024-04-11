package edu.handong.csee.java.hw4.engines;

// import edu.handong.csee.java.hw4.util.InputChecker;

public class GCDEngine implements Computable {
    private static final String engineName = "GCD";

    private int[] input;
    private int result;

    @Override
    public void setInput(String[] args) { 
        input = new int[args.length];
        for (int i  =0; i < input.length; i++)
            input[i] = Integer.parseInt(args[i]);
    }

    public void setResult(int result){ this.result =result; }

    @Override
    public void compute() {
        int a = input[0];
        int b = input[1];
        for (int i = 1; i < input.length; i++){
            b = input[i];
            result = a;
            while (b != 0) {
                int r = result % b;
                result = b;
                b = r;
            }
        }
    }

    public String getEnginName(){ return engineName; }
    
    public int[] getInput() {return input ;}
    
    @Override
    public double getResult() { return result; }
}
