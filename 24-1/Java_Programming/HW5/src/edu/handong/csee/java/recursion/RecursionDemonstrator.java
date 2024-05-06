package edu.handong.csee.java.recursion;
/**
 * runner class
 */
public class RecursionDemonstrator {
    /**
     * main method of program
     * @param args input parameters
     */
    public static void main(String[] args) {
        RecursionDemonstrator recursionDemonstrator = new RecursionDemonstrator();
        recursionDemonstrator.run(args);
    }
    /**
     * run method 
     * @param args input parameters
     */
    public void run(String[] args) {

        RecursionTasks recursionTasks = new RecursionTasks();

        recursionTasks.setTaskName(args[0]);
        recursionTasks.setInput(args);

        switch (recursionTasks.getTaskName()) {
            case "factorial": {
                int temp = Integer.parseInt(recursionTasks.getInput()[0]);
                recursionTasks.setResult(String.valueOf(recursionTasks.factorial(temp)));
                break;
            }
            case "bunnyEars": {
                int temp = Integer.parseInt(recursionTasks.getInput()[0]);
                recursionTasks.setResult(String.valueOf(recursionTasks.bunnyEars(temp)));
                break;
            }
            case "countHi": {
                String temp = recursionTasks.getInput()[0];
                recursionTasks.setResult(String.valueOf(recursionTasks.countHi(temp)));
                break;
            }
            case "changePi": {
                String temp = recursionTasks.getInput()[0];
                recursionTasks.setResult(String.valueOf(recursionTasks.changePi(temp)));
                break;
            }
            case "endX": {
                String temp = recursionTasks.getInput()[0];
                recursionTasks.setResult(String.valueOf(recursionTasks.endX(temp)));
                break;
            }
            case "stringClean": {
                String temp = recursionTasks.getInput()[0];
                recursionTasks.setResult(String.valueOf(recursionTasks.stringClean(temp)));
                break;
            }
            case "strDist": {
                String[] temp = recursionTasks.getInput();
                recursionTasks.setResult(String.valueOf(recursionTasks.strDist(temp[0], temp[1])));
                break;
            }
            case "decimal2binary": {
                int temp = Integer.parseInt(recursionTasks.getInput()[0]);
                recursionTasks.setResult(String.valueOf(recursionTasks.decimal2binary(temp)));
                break;
            }
            case "decodeString": {
                String temp = recursionTasks.getInput()[0];
                recursionTasks.setResult(String.valueOf(recursionTasks.decodeString(temp)));
                break;
            }
            case "parseBoolExpr": {
                String temp = recursionTasks.getInput()[0];
                recursionTasks.setResult(String.valueOf(recursionTasks.parseBoolExpr(temp)));
                break;
            }
            default: {
                System.out.println(
                        "Please put a computing recursion task option such as factorial, bunnyEars, countHi, changePi, " +
                                "endX, stringClean, strDist, decimal2binary, decodeString and parseBoolExpr. For example, " +
                                "java -cp [your classpath] edu.handong.csee.java.recursion.RecursionDemonstrator factorial 10");

                return;
            }
        }
        System.out.print("The result of " + recursionTasks.getTaskName() + " is ");
        System.out.println(recursionTasks.getResult() + ".");
    }
}