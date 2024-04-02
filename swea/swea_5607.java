// Solve 2024-04-01

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_5607 {

    static final int MOD = 1234567891;
    static long[] factorial = new long[1000001];

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
        factorial[0] = factorial[1] = 1;

        for (int i = 2; i <= 1000000; i++) {
            factorial[i] = factorial[i - 1] * i % MOD;
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            long ans = getPower(factorial[n - r] * factorial[r] % MOD, MOD - 2) * factorial[n] % MOD;
            sb.append("#").append(ti).append(" ").append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
