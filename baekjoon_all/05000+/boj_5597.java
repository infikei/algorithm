// Solve 2023-11-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_5597 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean students[] = new boolean[31];

        for (int i = 1; i <= 30; i++) {
            students[i] = false;
        }

        for (int i = 0; i < 28; i++) {
            int x = sc.nextInt();
            students[x] = true;
        }

        sc.close();

        for (int i = 1; i <= 30; i++) {
            if (!students[i]) {
                System.out.println(i);
            }
        }
    }
}
