// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0198_solution3 {

    int recur(int cur, int[] memo, int[] nums) {
        if (cur < 0) return 0;
        if (cur == 0) return nums[0];
        if (cur == 1) return Math.max(nums[0], nums[1]);
        if (memo[cur] != -1) return memo[cur];

        int ret = Math.max(recur(cur - 1, memo, nums), recur(cur - 2, memo, nums) + nums[cur]);
        return memo[cur] = ret;
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] memo = new int[n];

        for (int i = 0; i < n; i++) {
            memo[i] = -1;
        }

        return recur(n - 1, memo, nums);
    }

}
