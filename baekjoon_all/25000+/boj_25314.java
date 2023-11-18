// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_25314 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int n4 = n / 4;

        for (int i = 0; i < n4; i++) {
            System.out.print("long ");
        }
        System.out.println("int");

        sc.close();
    }
}
