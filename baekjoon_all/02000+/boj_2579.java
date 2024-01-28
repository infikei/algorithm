// Solve 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2579 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] scores = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            scores[i] = Integer.parseInt(br.readLine());
        }

        int[][] dp = new int[n + 1][2];
        dp[1][0] = scores[1];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = Math.max(dp[i - 2][0], dp[i - 2][1]) + scores[i];
            dp[i][1] = dp[i - 1][0] + scores[i];
        }

        System.out.println(Math.max(dp[n][0], dp[n][1]));
        br.close();
    }

}
