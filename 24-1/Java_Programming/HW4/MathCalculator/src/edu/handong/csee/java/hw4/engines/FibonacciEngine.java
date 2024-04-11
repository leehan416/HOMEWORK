package edu.handong.csee.java.hw4.engines;

public class FibonacciEngine implements Computable {
    private static final String engineName ="FIBONACCI";

    int n;
    double result;
    
    @Override
    public void setInput(String[] args) { n = Integer.parseInt(args[1]); }
    
    public void setResult(double result){ this.result = result; }
    
    @Override
    public void compute() {
        int a1 = 1;
        int a2 = 1;
        result = 1;
        if(n <= 2) return;
        for (int i = 2; i < n; i++) {
            int temp = a1 + a2;
            a2 = a1;
            a1 = temp;
            result = temp;
        }
    }

    public String getEnginName(){ return engineName; }

    public int getN() { return n; }

   
    @Override
    public double getResult() { return result; }

}
