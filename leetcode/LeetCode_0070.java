// Solve 2025-06-15

class LeetCode_0070 {

    int recur(int cur, int[] memo) {
        if (cur < 0) return 0;
        if (cur == 0) return 1;
        if (memo[cur] != 0) return memo[cur];

        int ret = recur(cur - 2, memo) + recur(cur - 1, memo);
        return memo[cur] = ret;
    }

    public int climbStairs(int n) {
        int[] memo = new int[n + 1];
        return recur(n, memo);
    }

}
