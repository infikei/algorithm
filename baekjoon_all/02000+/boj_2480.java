// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_2480 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int answer = 0;

        if (a == b && b == c) {
            answer = 10000 + a * 1000;
        } else if (a == b || a == c) {
            answer = 1000 + a * 100;
        } else if (b == c) {
            answer = 1000 + b * 100;
        } else {
            answer = Math.max(a, Math.max(b, c)) * 100;
        }

        System.out.println(answer);

        sc.close();
    }
}
