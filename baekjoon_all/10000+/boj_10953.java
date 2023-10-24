// Solve 2023-10-18
// Update 2023-10-23

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;
import java.util.StringTokenizer;

public class boj_10953 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();

        for (int testIdx = 0; testIdx < testNum; testIdx++) {
            String input = sc.next();
            StringTokenizer st = new StringTokenizer(input, ",");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            System.out.println(a + b);
        }

        sc.close();
    }
}
