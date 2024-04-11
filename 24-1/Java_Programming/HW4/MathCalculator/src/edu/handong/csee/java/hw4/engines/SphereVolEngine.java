// done


package edu.handong.csee.java.hw4.engines;

public class SphereVolEngine implements Computable {
    private static final String engineName ="SPHEREVOL";

    private double radius;
    private double result;
    
    @Override
    public void setInput(String[] args) { radius = Double.parseDouble(args[1]); }
    
    public void setResult(double result) { this.result = result; }

    @Override
    public void compute() { result = 4/3 * Math.pow(radius, 3)* Math.PI; }

    public String getEnginName(){ return engineName; }

    public double getRadius(){ return radius; }

    @Override
    public double getResult() { return result; }
}
