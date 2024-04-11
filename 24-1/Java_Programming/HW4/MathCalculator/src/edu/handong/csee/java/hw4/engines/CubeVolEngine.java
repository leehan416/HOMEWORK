package edu.handong.csee.java.hw4.engines;

// import edu.handong.csee.java.hw4.util.InputChecker;

public class CubeVolEngine implements Computable {
    private static final String engineName = "CUBEVOL";

    private double sideLength;
    private double volume;

    @Override
    public void compute() { volume = Math.pow(sideLength, 3); }

    @Override
    public void setInput(String[] args) { sideLength = Double.parseDouble(args[1]); }

    public void setVolume(double volume) { this.volume = volume; }

    public String getEnginName() { return engineName; }

    public double getSideLength() { return sideLength; }

    @Override
    public double getResult() { return volume; }

}
