package edu.handong.csee.java.recursion;


/**
 * Recursion Tasks class. 
 */
public class RecursionTasks {
    private String taskName;
    private String[] input;
    private String result;
    /**
     * Setter of TaskName
     * @param taskName new String data of TaskName
     */
    public void setTaskName(String taskName) {
        this.taskName = taskName;
    }
    /**
     * Setter of Input
     * @param input new String[] data of Input
     */
    public void setInput(String[] input) {
        taskName = input[0];
        this.input = new String[input.length - 1];

        for (int i = 1; i < input.length; i++)
            this.input[i - 1] = input[i];

    }
    /**
     * Setter of Result
     * @param result new String data of result
     */
    public void setResult(String result) {
        this.result = result;
    }

    /**
     * Getter of TaskName
     * @return data of TaskName as a String
     */
    public String getTaskName() {
        return taskName;
    }

    /**
     * Getter of Inputs
     * @return data of inputs as a String[]
     */
    public String[] getInput() {
        return input;
    }

    /**
     * Getter of Result
     * @return data of result as String
     */
    public String getResult() {
        return result;
    }

    /**
     * factorial method
     * @param num 
     * @return result of factorial (num!)
     */
    public int factorial(int num) {
        if (num <= 1) return 1;
        else return factorial(num - 1) * num;
    }

    /**
     * count bunnys Ears method. it count 2 each bunnys (odd). and when they are raised leg, it count 3(even)
     * @param num num of bunnys
     * @return result of count
     */
    public int bunnyEars(int num) {
        if (num == 0) return 0;
        else if (num % 2 == 1) return bunnyEars(num - 1) + 2;
        else return bunnyEars(num - 1) + 3;
    }

    /**
     * count hi on the sentence 
     * @param str sentence 
     * @return result of count
     */
    public int countHi(String str) {
        if (str.length() <= 1) return 0;
        String temp = String.valueOf(str.charAt(0)) + String.valueOf(str.charAt(1));
        if (temp.toLowerCase().equals("hi")) return countHi(str.substring(1, str.length())) + 1;
        else return countHi(str.substring(1, str.length())) + 0;
    }

    /**
     * change "pi" to 3.14 on the sentence
     * @param str sentence
     * @return result of changing
     */
    public String changePi(String str) {
        if (str.length() <= 1) return str;
        String temp = String.valueOf(str.charAt(0)) + String.valueOf(str.charAt(1));
        if (temp.toLowerCase().equals("pi")) return "3.14" + changePi(str.substring(2, str.length()));
        else return temp.charAt(0) +  changePi(str.substring(1, str.length()));
    }

    /**
     * move 'x' to the end of sentence
     * @param str sentence 
     * @return result of moving
     */
    public String endX(String str) {
        if (str.isEmpty()) return "";
        String temp = String.valueOf(str.charAt(0));
        if (temp.equals("x")) return endX(str.substring(1)) + "x";
        else return temp + endX(str.substring(1));
    }

    /**
     * make clean the string. remove duplicated alphaBat
     * @param str String.
     * @return result of remove as String
     */
    public String stringClean(String str) {
        if (str.length() == 0 || str.length() == 1) return str;
        String temp = String.valueOf(str.charAt(0)) + String.valueOf(str.charAt(1));
        if (temp.charAt(0) == temp.charAt(1)) return  stringClean(str.substring(1));
        else return str.charAt(0) + stringClean(str.substring(1));
    }

    /**
     * count AlphaBats between [sub] on [str]
     * @param str String
     * @param sub String
     * @return result of count as int
     */
    public int strDist(String str, String sub) {
        if (str.length() < sub.length()) return 0;
        if (str.startsWith(sub)) {
            if (str.endsWith(sub)) return str.length();
            else return strDist(str.substring(0, str.length() - 1), sub);
        } else return strDist(str.substring(1), sub);
    }

    /**
     * change decimal num to binary num
     * @param num decimal num
     * @return result of changing as int
     */
    public String decimal2binary(int num) {
        if (num <= 1) return String.valueOf(num);
        int temp = num / 2;
        if (num % 2 == 1) return decimal2binary(temp) + "1";
        else return decimal2binary(temp) + "0";
    }

    /**
     * encoding String. repeat num on the String []
     * @param s String  (ex. 3[a]2[b])
     * @return String (ex. aaabb)
     */
    public String decodeString(String s) {
        String result = "";
        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);

            if (Character.isDigit(curr)) {
                while (Character.isDigit(curr)) {
                    num = num * 10 + (curr - '0');
                    curr = s.charAt(++i);
                }
                if (curr == '[') {
                    int stack = 1;
                    String temp = "";
                    while (stack != 0) {
                        curr = s.charAt(++i);
                        if (curr == '[') stack++;
                        if (curr == ']') stack--;
                        temp += curr;
                    }

                    temp = temp.substring(0, temp.length() - 1);
                    for (int j = 0; j < num; j++)
                        result += decodeString(temp);
                    num = 0;
                }
            } else {
                curr = s.charAt(i);
                result += curr;
            }
        }
        return result;
    }

    /**
     * Get result of boolean expression 
     * @param str String (ex. |(f,f,f,t))
     * @return boolean
     */
    public boolean parseBoolExpr(String str) {
        if (str.equals("t")) return true;
        if (str.equals("f")) return false;
        char operator = str.charAt(0);
        String temp = str.substring(2, str.length() - 1);
        String[] arr = temp.split(",");

        switch (operator) {
            case '!': {
                return !parseBoolExpr(temp);
            }
            case '&': {
                for (String i : arr)
                    if (!parseBoolExpr(i)) return false;
                return true;
            }
            case '|': {
                for (String i : arr)
                    if (parseBoolExpr(i)) return true;
                return false;
            }
        }
        return false;
    }
}