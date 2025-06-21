// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0746_solution4 {

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] memo = new int[n + 1];

        for (int i = 2; i <= n; i++) {
            memo[i] = Math.min(memo[i - 2] + cost[i - 2], memo[i - 1] + cost[i - 1]);
        }

        return memo[n];
    }

}
