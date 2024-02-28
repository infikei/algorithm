// Solve 2024-02-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1463 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] memo = new int[n + 1];

        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1];

            if (i % 3 == 0) {
                memo[i] = Math.min(memo[i], memo[i / 3]);
            }

            if (i % 2 == 0) {
                memo[i] = Math.min(memo[i], memo[i / 2]);
            }

            memo[i]++;
        }

        System.out.println(memo[n]);
        br.close();
    }

}
