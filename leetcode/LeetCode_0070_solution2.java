// Solve 2025-06-15

class LeetCode_0070_solution2 {

    public int climbStairs(int n) {
        int[] memo = new int[n + 1];

        memo[0] = memo[1] = 1;

        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 2] + memo[i - 1];
        }

        return memo[n];
    }

}
