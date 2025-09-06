// Solve 2025-07-27
// Update 2025-09-05

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_20544 {

    static final long MOD = 1000000007;

    static long[] memo2 = new long[1001];
    static long[] memo = new long[1001];

    static void init() {
        for (int i = 0; i <= 1000; i++) {
            memo2[i] = -1;
            memo[i] = -1;
        }
    }

    static long count_for_max_height_2(int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;
        if (memo2[x] != -1) return memo2[x];

        long ret = 0;
        ret += count_for_max_height_2(x - 1);
        ret += count_for_max_height_2(x - 2) * 2;
        ret += count_for_max_height_2(x - 3) * 3;
        return memo2[x] = ret % MOD;
    }

    static long count_for_max_height_1(int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;
        if (memo[x] != -1) return memo[x];

        long ret = 0;
        ret += count_for_max_height_1(x - 1);
        ret += count_for_max_height_1(x - 2);
        ret += count_for_max_height_1(x - 3);
        return memo[x] = ret % MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        init();
        long ans = (count_for_max_height_2(n) - count_for_max_height_1(n) + MOD) % MOD;
        System.out.println(ans);
    }

}
