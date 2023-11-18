// Solve 2023-11-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_3052 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean existRemainder[] = new boolean[42];

        for (int i = 0; i < 42; i++) {
            existRemainder[i] = false;
        }

        for (int i = 0; i < 10; i++) {
            int x = sc.nextInt();
            existRemainder[x % 42] = true;
        }

        sc.close();
        int cnt = 0;

        for (int i = 0; i < 42; i++) {
            if (existRemainder[i]) {
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}
