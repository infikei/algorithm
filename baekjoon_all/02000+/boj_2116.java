// Solve 2024-02-09

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2116 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        int[] dp = new int[7];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int[] dice = new int[6];

            for (int j = 0; j < 6; j++) {
                dice[j] = Integer.parseInt(st.nextToken());
            }

            int m = 6;

            while (dice[0] == m || dice[5] == m) {
                m--;
            }

            dp[dice[0]] += m;
            dp[dice[5]] += m;
            swap(dp, dice[0], dice[5]);

            m = 6;

            while (dice[1] == m || dice[3] == m) {
                m--;
            }

            dp[dice[1]] += m;
            dp[dice[3]] += m;
            swap(dp, dice[1], dice[3]);

            m = 6;

            while (dice[2] == m || dice[4] == m) {
                m--;
            }

            dp[dice[2]] += m;
            dp[dice[4]] += m;
            swap(dp, dice[2], dice[4]);
        }

        int ans = 0;

        for (int i = 1; i <= 6; i++) {
            ans = Math.max(ans, dp[i]);
        }

        System.out.println(ans);
        br.close();
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}
