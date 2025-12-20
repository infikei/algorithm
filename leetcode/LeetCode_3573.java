// Solve 2025-12-17

class LeetCode_3573 {

    final long INF = 0x3f3f3f3f3f3f3f3fL;

    long[][][] memo;

    long recur(int cur, int k, int state, int[] prices) {
        if (cur + 1 == prices.length) {
            if (state == 1) return prices[cur];
            if (state == 2) return -prices[cur];
            return 0L;
        }
        if (k == 0) return 0L;
        if (memo[cur][k][state] != -INF) return memo[cur][k][state];

        long ret = recur(cur + 1, k, state, prices);

        if (state == 1) {
            ret = Math.max(ret, recur(cur + 1, k - 1, 0, prices) + prices[cur]);
        } else if (state == 2) {
            ret = Math.max(ret, recur(cur + 1, k - 1, 0, prices) - prices[cur]);
        } else {
            ret = Math.max(ret, recur(cur + 1, k, 1, prices) - prices[cur]);
            ret = Math.max(ret, recur(cur + 1, k, 2, prices) + prices[cur]);
        }

        memo[cur][k][state] = ret;
        return ret;
    }

    public long maximumProfit(int[] prices, int k) {
        memo = new long[prices.length][k + 1][3];

        for (int i = 0; i < prices.length; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s < 3; s++) {
                    memo[i][j][s] = -INF;
                }
            }
        }

        return recur(0, k, 0, prices);
    }

}
