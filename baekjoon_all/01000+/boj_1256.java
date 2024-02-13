// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1256 {

    public static void main(String[] args) throws IOException {
        int[][] comb = new int[201][201];
        comb[0][0] = 1;
        comb[1][0] = 1;
        comb[1][1] = 1;

        for (int i = 2; i <= 200; i++) {
            comb[i][0] = 1;

            for (int j = 1; j <= i; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];

                if (comb[i][j] >= 1_000_000_001) {
                    comb[i][j] = 1_000_000_001;
                }
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        if (k > comb[n + m][n]) {
            sb.append("-1\n");
        } else {
            int iter = n + m;

            while (iter-- > 0) {
                if (n == 0) {
                    sb.append("z");
                    continue;
                } else if (m == 0) {
                    sb.append("a");
                    continue;
                }

                if (k <= comb[n + m - 1][n - 1]) {
                    n--;
                    sb.append("a");
                } else {
                    k -= comb[n + m - 1][n - 1];
                    m--;
                    sb.append("z");
                }
            }
        }

        System.out.println(sb);
        br.close();
    }

}
