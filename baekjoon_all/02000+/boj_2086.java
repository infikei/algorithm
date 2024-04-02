// Solve 2024-04-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2086 {

    static final long MOD = 1_000_000_000;

    static long[][] multiplyMatrix(long[][] a, long[][] b) {
        long[][] res = new long[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res[i][j] += a[i][k] * b[k][j] % MOD;
                }

                res[i][j] %= MOD;
            }
        }

        return res;
    }

    static long[][] powerMatrix(long[][] a, long b) {
        long[][] res = new long[2][2];

        for (int i = 0; i < 2; i++) {
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
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        long[][] mat1 = {
            { 1, 1 },
            { 1, 0 }
        };

        long[][] mat2 = {
            { 1, 1 },
            { 1, 0 }
        };

        long[][] res1 = powerMatrix(mat1, a + 1);
        long[][] res2 = powerMatrix(mat2, b + 2);
        long ans = (res2[1][0] - res1[1][0] + MOD) % MOD;

        System.out.println(ans);
        br.close();
    }

}
