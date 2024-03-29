// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_2884 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int hour = sc.nextInt();
        int minute = sc.nextInt();

        minute -= 45;

        if (minute < 0) {
            minute += 60;
            hour--;
        }

        if (hour < 0) {
            hour += 24;
        }

        System.out.println(hour + " " + minute);

        sc.close();
    }
}
