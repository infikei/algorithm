// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0746_solution3 {

    int recur(int cur, int[] memo, int[] cost) {
        if (cur < 0) return 1000000;
        if (cur <= 1) return 0;
        if (memo[cur] != -1) return memo[cur];

        int ret = Math.min(recur(cur - 2, memo, cost) + cost[cur - 2], recur(cur - 1, memo, cost) + cost[cur - 1]);
        return memo[cur] = ret;
    }

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] memo = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            memo[i] = -1; // cost[i]가 0으로 주어질 수 있으므로, memo[i]의 초기값을 0으로 설정할 수 없음
        }

        return recur(n, memo, cost);
    }

}
