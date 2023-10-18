// Solve 2023-10-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.util.Scanner;
import java.util.StringTokenizer;

public class boj_10953 {
    public static void main(String[] args) {
        Scanner sc;
        int testNum;

        sc = new Scanner(System.in);
        testNum = sc.nextInt();

        for (int testIdx = 0; testIdx < testNum; testIdx++) {
            String input;
            StringTokenizer st;
            int a;
            int b;

            input = sc.next();
            st = new StringTokenizer(input, ",");
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            System.out.println(a + b);
        }

        sc.close();
    }
}
