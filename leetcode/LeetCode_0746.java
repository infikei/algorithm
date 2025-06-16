// Solve 2025-06-15

class LeetCode_0746 {

    int recur(int cur, int[] memo, int[] cost) {
        if (cur < 0) return 1000000;
        if (cur <= 1) return cost[cur];
        if (memo[cur] != -1) return memo[cur];

        int ret = Math.min(recur(cur - 2, memo, cost), recur(cur - 1, memo, cost));
        ret += cost[cur];
        return memo[cur] = ret;
    }

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] memo = new int[n];

        for (int i = 0; i < n; i++) {
            memo[i] = -1; // cost[i]가 0으로 주어질 수 있으므로, memo[i]의 초기값을 0으로 설정할 수 없음
        }

        return Math.min(recur(n - 2, memo, cost), recur(n - 1, memo, cost));
    }

}
