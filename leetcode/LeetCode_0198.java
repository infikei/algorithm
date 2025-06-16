// Solve 2025-06-15

class LeetCode_0198 {

    int recur(int cur, int[] memo, int[] nums) {
        if (cur < 0) return 0;
        if (cur <= 1) return nums[cur];
        if (cur == 2) return nums[0] + nums[2];
        if (memo[cur] != -1) return memo[cur];

        int ret = Math.max(recur(cur - 3, memo, nums), recur(cur - 2, memo, nums));
        ret += nums[cur];
        return memo[cur] = ret;
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] memo = new int[n];

        for (int i = 0; i < n; i++) {
            memo[i] = -1;
        }

        return Math.max(recur(n - 2, memo, nums), recur(n - 1, memo, nums));
    }

}
