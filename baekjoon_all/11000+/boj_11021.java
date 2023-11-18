// Solve 2023-10-18
// Update 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;

public class boj_11021 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCaseNumber = sc.nextInt();

        for (int testCaseIndex = 1; testCaseIndex <= testCaseNumber; testCaseIndex++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println("Case #" + testCaseIndex + ": " + (a + b));
        }

        sc.close();
    }
}
