// Solve 2024-04-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_27435 {

    static final long MOD = 998_244_353;

    static long[][] multiplyMatrix(long[][] a, long[][] b) {
        long[][] res = new long[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    res[i][j] += a[i][k] * b[k][j] % MOD;
                }

                res[i][j] %= MOD;
            }
        }

        return res;
    }

    static long[][] powerMatrix(long[][] a, long b) {
        long[][] res = new long[5][5];

        for (int i = 0; i < 5; i++) {
            res[i][i] = 1;
        }

        while (b > 0) {
            if ((b & 1) == 1) {
                res = multiplyMatrix(res, a);
            }

            a = multiplyMatrix(a, a);
            b >>= 1;
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            long n = Long.parseLong(br.readLine());

            if (n <= 3) {
                sb.append(1).append("\n");
                continue;
            }

            if (n <= 5) {
                sb.append(2).append("\n");
                continue;
            }

            long[][] mat = {
                { 1, 0, 0, 0, 1 },
                { 1, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 0, 1, 0 }
            };

            long[][] res = powerMatrix(mat, n - 5);
            long ans = (res[0][0] * 2 + res[0][1] * 2 + res[0][2] + res[0][3] + res[0][4]) % MOD;
            sb.append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
