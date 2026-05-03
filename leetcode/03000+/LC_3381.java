// Solve 2025-11-27
// Update 2025-12-05

class LeetCode_3381 {

    public long maxSubarraySum(int[] nums, int k) {
        long curSum = 0;

        for (int i = 0; i < k; i++) {
            curSum += nums[i];
        }

        long[] memo = new long[nums.length];
        memo[k - 1] = curSum;
        long mx = curSum;

        for (int i = k; i < nums.length; i++) {
            curSum += nums[i];
            curSum -= nums[i - k];

            memo[i] = Math.max(memo[i - k], 0L) + curSum;
            mx = Math.max(mx, memo[i]);
        }

        return mx;
    }

}
