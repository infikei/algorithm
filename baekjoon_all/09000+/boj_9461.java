// Solve 2024-04-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9461 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        long[] padovan = new long[101];
        padovan[1] = padovan[2] = padovan[3] = 1;
        padovan[4] = padovan[5] = 2;

        for (int i = 6; i <= 100; i++) {
            padovan[i] = padovan[i - 5] + padovan[i - 1];
        }

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            sb.append(padovan[n]).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
