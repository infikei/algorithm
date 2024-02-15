// Solve 2024-02-15

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_14613 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        double win = Double.parseDouble(st.nextToken());
        double lose = Double.parseDouble(st.nextToken());
        double draw = Double.parseDouble(st.nextToken());

        double[][] dp = new double[21][62];

        for (int round = 0; round <= 20; round++) {
            dp[round] = new double[62];
        }

        dp[0][40] = 1.0;

        for (int round = 1; round <= 20; round++) {
            for (int score = 10; score <= 60; score++) {
                dp[round][score] = dp[round - 1][score - 1] * win + dp[round - 1][score] * draw + dp[round - 1][score + 1] * lose;
            }
        }

        double[] probByTier = new double[5];

        for (int score = 20; score < 30; score++) {
            probByTier[0] += dp[20][score];
        }

        for (int score = 30; score < 40; score++) {
            probByTier[1] += dp[20][score];
        }

        for (int score = 40; score < 50; score++) {
            probByTier[2] += dp[20][score];
        }

        for (int score = 50; score < 60; score++) {
            probByTier[3] += dp[20][score];
        }

        probByTier[4] = dp[20][60];

        for (int i = 0; i < 5; i++) {
            System.out.printf("%.8f%n", probByTier[i]);
        }

        br.close();
    }

}
