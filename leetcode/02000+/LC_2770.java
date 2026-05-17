// Solve 2026-05-10

class LC_2770 {

    public int maximumJumps(int[] nums, int target) {
        int n = nums.length;
        int[] memo = new int[n];

        for (int i = 0; i < n; i++) {
            memo[i] = -1;
        }

        memo[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (memo[j] == -1) continue;

                int diff = Math.abs(nums[i] - nums[j]);

                if (diff <= target) {
                    memo[i] = Math.max(memo[i], memo[j] + 1);
                }
            }
        }

        return memo[n - 1];
    }

}
