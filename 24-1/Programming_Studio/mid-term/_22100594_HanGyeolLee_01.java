import java.util.Scanner;

public class _22100594_HanGyeolLee_01 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int temp;
        int sum = 0;
        int max = Integer.MIN_VALUE;
        int maxIndex = 0;
        int min = Integer.MAX_VALUE;
        int minIndex = 0;
        for (int i = 0; i < num; i++) {
            temp = sc.nextInt();
            sum += temp;
            if (temp < min) {
                minIndex = i + 1;
                min = temp;
            } else if (max < temp) {
                maxIndex = i + 1;
                max = temp;
            }
        }
        System.out.println("Sum: " + sum);
        System.out.println("Average: " + (double) sum / num);
        System.out.println(String.format("Max: %d(%d)", max, maxIndex));
        System.out.println(String.format("Min: %d(%d)", min, minIndex));


    }


}
