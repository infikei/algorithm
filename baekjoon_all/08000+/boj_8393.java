// Solve 2023-10-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_8393 {
    public static void main(String[] args) {
        Scanner sc;
        int n;

        sc = new Scanner(System.in);
        n = sc.nextInt();

        System.out.println(n * (n + 1) / 2);

        sc.close();
    }
}
