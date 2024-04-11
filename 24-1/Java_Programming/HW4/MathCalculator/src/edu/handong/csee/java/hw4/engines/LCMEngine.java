package edu.handong.csee.java.hw4.engines;

// import javax.swing.Spring;

// import edu.handong.csee.java.hw4.util.InputChecker;

public class LCMEngine implements Computable{
    private static final String engineName ="LCM";

    private int[] input;
    
    private int result;
    
    @Override
    public void setInput(String[] args) {
            input =new int[args.length];
            for (int i = 0; i < args.length; i++)
                input[i] = Integer.parseInt(args[i]);
    }

    public void setResult(int result){ this.result = result; }
    
    @Override
    public void compute() {
        int max = Integer.MIN_VALUE;

        int isValid = 0; // 0-> is valid  >= 1-> isnt valid 


        for (int i : input) 
            if (max > i) max = i;

        for (int i = 1; i < max; i++){
            int temp = max * i;
            for (int j : input) 
                if (temp % j > 0) isValid += 1;

            if (isValid == 0){
                result = temp;
                break;
            }
        }
        
    }


    public String getEngineName(){ return engineName; }

    public int[] getInput(){ return input;}

    @Override
    public double getResult() { return result; }
    
    
}
