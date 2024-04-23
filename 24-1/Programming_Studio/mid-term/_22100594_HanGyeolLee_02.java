import java.util.Scanner;

public class _22100594_HanGyeolLee_02 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        String input = sc.next();
        String temp = String.valueOf(input.charAt(input.length()-1) + input.charAt(input.length()-2));
        if (
                input.charAt(input.length()-1) == 's' || input.charAt(input.length()-1) == 'x'
             || input.charAt(input.length()-1) == 'z' || temp.equals("ch") || temp.equals("sh")
        ) {
            input += "es";



        } else {
            input += "s";
        }

        System.out.println(input);

    }
}
