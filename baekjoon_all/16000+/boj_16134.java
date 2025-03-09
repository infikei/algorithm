// Solve 2024-04-01
// Update 2025-03-09

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_16134 {

    static final int MOD = 1_000_000_007;

    static long[] createFactorialArr(int n) {
        long[] factorialArr = new long[n + 1];
        factorialArr[0] = factorialArr[1] = 1;

        for (int i = 2; i <= n; i++) {
            factorialArr[i] = factorialArr[i - 1] * i % MOD;
        }

        return factorialArr;
    }

    static long getPower(long a, int b) {
        long res = 1;

        while (b > 0) {
            if ((b & 1) == 1) {
                res = res * a % MOD;
            }

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        long[] factorialArr = createFactorialArr(n);

        long ans = getPower(factorialArr[n - r] * factorialArr[r] % MOD, MOD - 2) * factorialArr[n] % MOD;
        System.out.println(ans);
    }

}
