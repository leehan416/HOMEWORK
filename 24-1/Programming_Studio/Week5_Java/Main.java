package week5;

import java.text.Format;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main pStudio = new Main();

        // code here
//        pStudio.J001();
    }

    // ----------------------------------------------------
    void J001() { // 이 곳에서 문제 번호에 해당하는 method를 완성함

        Scanner sc = new Scanner(System.in);

        int height, weight; // 신장(cm), 체중(kg)
        double bmi; // 비만도 수치

        // input
        height = sc.nextInt();
        weight = sc.nextInt();

        // 연산
        double heightD = height * 0.01f;
        bmi = weight / Math.pow(heightD, 2);

        // 출력
        System.out.println(String.format("%.1f", bmi));
    }

    void J002() {
        double c_degree; // 섭씨 온도
        double f_degree; // 화씨 온도

        Scanner sc = new Scanner(System.in);

        c_degree = sc.nextFloat();

        System.out.println(String.format("%.1f", c_degree * 1.8 + 32));
    }

    void J003() {
        double m2_area; // 면적 (제곱미터)
        double pyung_area; // 면적 (평수)

        Scanner sc = new Scanner(System.in);

        m2_area = sc.nextFloat();
        pyung_area = m2_area / 3.305;
        System.out.println(String.format("%.1f", pyung_area));
    }

    void J004() {
        double x1, y1; // 첫 번째 좌표 값
        double x2, y2; // 두 번째 좌표 값

        double dis;
        Scanner sc = new Scanner(System.in);

        x1 = sc.nextFloat();
        y1 = sc.nextFloat();

        x2 = sc.nextFloat();
        y2 = sc.nextFloat();

        dis = Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2));
        System.out.println(String.format("%.1f", dis));
    }

    void J005() {
        int month, day; // 월, 일
        int day_count = 0; // 1년 중 날 수

        Scanner sc = new Scanner(System.in);

        month = sc.nextInt();
        day = sc.nextInt();

        for (int i = 1; i < month; i++) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                day_count += 31;
            else if (i == 2)
                day_count += 28;
            else
                day_count += 30;
        }
        day_count += day;
        System.out.println(day_count);

    }

    // ----------------------------------------------------
    // Lab02
    void J011() {

        Scanner sc = new Scanner(System.in);

        int height, weight; // 신장(cm), 체중(kg)
        double bmi; // 비만도 수치

        // input
        height = sc.nextInt();
        weight = sc.nextInt();

        // 연산
        double heightD = height * 0.01f;
        bmi = weight / Math.pow(heightD, 2);
        System.out.println((bmi >= 25) ? "Yes" : "no");
    }

    // ----------------------------------------------------
    void J012() {
        double m2_area; // 면적 (제곱미터)
        double pyung_area; // 면적 (평수)
        String[] text = {"small", "normal", "large", "huge"};
        int index;

        Scanner sc = new Scanner(System.in);

        m2_area = sc.nextFloat();
        pyung_area = m2_area / 3.305;

        if (50 <= pyung_area)
            index = 3;
        else if (30 <= pyung_area)
            index = 2;
        else if (15 <= pyung_area)
            index = 1;
        else
            index = 0;

        // 15평 미만 : small
        // 15평 이상 ~ 30평 미만 : normal
        // 30평 이상 ~ 50평 미만 : large
        // 50평 이상 : huge

        System.out.println(String.format("%.1f", pyung_area));
        System.out.println(text[index]);
    }
    // ----------------------------------------------------

    void J013() {
        Scanner sc = new Scanner(System.in);
        int kor, eng, math;
        int total;
        double average;

        String p, f;
        p = "Pass";
        f = "Fail";

        kor = sc.nextInt();
        eng = sc.nextInt();
        math = sc.nextInt();

        total = kor + eng + math;

        average = total / 3.0f;
        System.out.println(String.format("%d %.1f", total, average));
        System.out.println("Korean - " + ((kor >= 70) ? p : f));
        System.out.println("Englisg - " + ((eng >= 70) ? p : f));
        System.out.println("Math - " + ((math >= 70) ? p : f));
        System.out.println();
    }
    // ----------------------------------------------------

    void J014() {
        int income; // 연봉 (원 단위)
        double tax; // 소득세 (원 단위)

        double percent;

        Scanner sc = new Scanner(System.in);

//                연봉 1천만 원 미만 : 연봉의 9.5%
//                연봉 1천만 원 이상 ~ 4천만원미만 : 연봉의 19%
//                연봉 4천만 원 이상 ~ 8천만원미만 : 연봉의 28%
//                연봉 8천만 원 이상 : 연봉의 37%
        income = sc.nextInt();

        if (income < 10000000) percent = 9.5;
        else if ((10000000 <= income) && (income < 40000000)) percent = 19;
        else if ((40000000 <= income) && (income < 80000000)) percent = 19;
        else percent = 37;

        tax = income * (percent / 100);
        System.out.println((int)tax);
    }


    void J015() {
        Scanner sc = new Scanner(System.in);
        int num1, num2, num3; // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자
        int max_num, min_num; // 가장 큰 숫자, 가장 작은 숫자
        int n = 3;
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        num3 = sc.nextInt();
        int[] num = {num1, num2, num3};

        // bubble sort
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (num[j] > num[j + 1]) {
                    int temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
        max_num = num[2];
        min_num = num[0];

        System.out.println(min_num + " " + max_num);
    }
    // ----------------------------------------------------


    void J021() {


        Scanner sc = new Scanner(System.in);
        int height, weight; // 신장(cm), 체중(kg)
        double bmi; // 비만도 수치
        int people;// 비만인 사람의 수
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {


        }


    }


}
