package edu.handong.csee.java.recursion;

public class RecursionTasks {
    private String taskName;
    private String[] input;
    private String result;

    public void setTaskName(String taskName) { this.taskName = taskName; }

    public void setInput(String[] input) {

    }

    public void setResult(String result) { this.result = result; }

    public String getTaskName() { return taskName; }

    public String[] getInput() { return input; }

    public String getResult() { return result; }

    public int factorial(int num) {
        if (num <= 1) return 1;
        else return factorial(num-1) * num; 
    }

    public int bunnyEars(int num) {
        if (num == 0) return 0;
        else if (num % 2 == 1)  return bunnyEars(num - 1) + 2;
        else return bunnyEars(num - 1) + 3;
    }

    public int countHi(String str) {
        if (str.length() <= 1) return 0;
        String temp =String.valueOf(str.charAt(0)) + String.valueOf(str.charAt(1));    
        if (temp.toLowerCase().equals("hi")) return countHi(str.substring(1, str.length())) + 1;
        else return countHi(str.substring(1, str.length())) + 0;
    }

    public String changePi(String str) {
        if (str.length() <= 1) return str;
        String temp =String.valueOf(str.charAt(0)) + String.valueOf(str.charAt(1));    
        if (temp.toLowerCase().equals("pi")) return "3.14" +  changePi(str.substring(1, str.length()));
        else return changePi(str.substring(1, str.length()));
    }

    public String endX(String str) {

    }

    public String stringClean(String str) {

    }

    public int strDist(String str1, String str2) {

    }

    public Stirng decimal2binary(int num) {

    }

    public String decodeString(String str) {

    }

    public boolean parseBoolExpr(String str) {
        return true;
    }

}
