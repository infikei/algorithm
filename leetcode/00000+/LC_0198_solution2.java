// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0198_solution2 {

    public int rob(int[] nums) {
        int n = nums.length;

        if (n == 1) return nums[0];

        int[] memo = new int[n];
        memo[0] = nums[0];
        memo[1] = nums[1];

        if (n >= 3) memo[2] = nums[0] + nums[2];

        for (int i = 3; i < n; i++) {
            memo[i] = Math.max(memo[i - 3], memo[i - 2]) + nums[i];
        }

        return Math.max(memo[n - 2], memo[n - 1]);
    }

}
