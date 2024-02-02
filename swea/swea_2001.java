// Solve 2024-02-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_2001 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] prefixSum = new int[n + 1][n + 1];

            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int j = 1; j <= n; j++) {
                    prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]
                            + Integer.parseInt(st.nextToken());
                }
            }

            int maxSum = 0;

            for (int i = m; i <= n; i++) {
                for (int j = m; j <= n; j++) {
                    int curSum = prefixSum[i][j] - prefixSum[i][j - m] - prefixSum[i - m][j] + prefixSum[i - m][j - m];
                    maxSum = Math.max(maxSum, curSum);
                }
            }

            sb.append("#").append(ti).append(" ").append(maxSum).append("\n");
        }

        System.out.println(sb);
        br.close();
    }

}
