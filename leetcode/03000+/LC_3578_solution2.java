// Solve 2025-12-07

import java.util.*;

class LeetCode_3578 {

    final int MOD = 1000000007;

    public int countPartitions(int[] nums, int k) {
        int n = nums.length;

        int[] memo = new int[n + 1];
        memo[0] = 1;
        int[] memoPrefix = new int[n + 1];
        memoPrefix[0] = 1;

        ArrayDeque<Integer> dequeAsc = new ArrayDeque<>();
        ArrayDeque<Integer> dequeDesc = new ArrayDeque<>();

        for (int i = 0, j = 0; i < n; i++) {
            while (!dequeAsc.isEmpty() && nums[dequeAsc.peekLast()] >= nums[i]) {
                dequeAsc.pollLast();
            }

            dequeAsc.addLast(i);

            while (!dequeDesc.isEmpty() && nums[dequeDesc.peekLast()] <= nums[i]) {
                dequeDesc.pollLast();
            }

            dequeDesc.addLast(i);

            while (nums[dequeDesc.peekFirst()] - nums[dequeAsc.peekFirst()] > k) {
                if (j == dequeAsc.peekFirst()) {
                    dequeAsc.pollFirst();
                }

                if (j == dequeDesc.peekFirst()) {
                    dequeDesc.pollFirst();
                }

                j++;
            }

            memo[i + 1] = (memoPrefix[i] - (j - 1 >= 0 ? memoPrefix[j - 1] : 0) + MOD) % MOD;
            memoPrefix[i + 1] = (memoPrefix[i] + memo[i + 1]) % MOD;
        }

        return memo[n];
    }

}
