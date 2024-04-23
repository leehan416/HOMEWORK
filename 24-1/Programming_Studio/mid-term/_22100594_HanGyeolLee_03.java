import java.util.Scanner;

public class _22100594_HanGyeolLee_03{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        int temp = num2 + num1;
        String tmp = String.valueOf(temp);

        System.out.print(tmp.charAt(0));
        for (int i = 0; i < tmp.length() -1; i++)
            System.out.print('0');
        System.out.println();





    }
}
