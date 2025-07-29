// Solve 2025-07-27

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_20544 {

    static final long MOD = 1000000007;

    static long[] memo2 = new long[1001];
    static long[] memo = new long[1001];

    static void init() {
        for (int i = 0; i <= 1000; i++) memo2[i] = -1;
        for (int i = 0; i <= 1000; i++) memo[i] = -1;
    }

    static long count_if_max_height_2(int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;
        if (memo2[x] != -1) return memo2[x];

        long ret = (count_if_max_height_2(x - 1) + count_if_max_height_2(x - 2) * 2 + count_if_max_height_2(x - 3) * 3) % MOD;
        return memo2[x] = ret;
    }

    static long count_if_max_height_1(int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;
        if (memo[x] != -1) return memo[x];

        long ret = (count_if_max_height_1(x - 1) + count_if_max_height_1(x - 2) + count_if_max_height_1(x - 3)) % MOD;
        return memo[x] = ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        init();
        int n = Integer.parseInt(br.readLine());
        long ans = (count_if_max_height_2(n) - count_if_max_height_1(n) + MOD) % MOD;
        System.out.println(ans);
    }

}
