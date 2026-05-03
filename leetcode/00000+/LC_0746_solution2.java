// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0746_solution2 {

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] memo = new int[n];
        memo[0] = cost[0];
        memo[1] = cost[1];

        for (int i = 2; i < n; i++) {
            memo[i] = Math.min(memo[i - 2], memo[i - 1]) + cost[i];
        }

        return Math.min(memo[n - 2], memo[n - 1]);
    }

}
