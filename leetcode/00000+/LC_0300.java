// Solve 2025-06-15

class LeetCode_0300 {

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] memo = new int[n];
        int ret = 0;

        for (int i = 0; i < n; i++) {
            memo[i] = 1;

            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    memo[i] = Math.max(memo[i], memo[j] + 1);
                }
            }

            ret = Math.max(ret, memo[i]);
        }

        return ret;
    }

}
