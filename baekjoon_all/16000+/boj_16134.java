// Solve 2024-04-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_16134 {

    static final int MOD = 1_000_000_007;

    static long getPower(long a, int b) {
        long res = 1;

        while (b > 0) {
            if ((b & 1) == 1) {
                res *= a;
                res %= MOD;
            }

            a *= a;
            a %= MOD;
            b >>= 1;
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        long[] factorial = new long[n + 1];
        factorial[0] = factorial[1] = 1;

        for (int i = 2; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i % MOD;
        }

        long ans = getPower(factorial[n - r] * factorial[r] % MOD, MOD - 2) * factorial[n] % MOD;
        System.out.println(ans);
        br.close();
    }

}
