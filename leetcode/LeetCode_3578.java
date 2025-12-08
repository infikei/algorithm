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

        PriorityQueue<int[]> pqMinTop = new PriorityQueue<>((o1, o2) -> {
            if (o1[1] != o2[1]) return Integer.compare(o1[1], o2[1]);
            return Integer.compare(o1[0], o2[0]);
        });
        PriorityQueue<int[]> pqMaxTop = new PriorityQueue<>((o1, o2) -> {
            if (o1[1] != o2[1]) return Integer.compare(o2[1], o1[1]);
            return Integer.compare(o1[0], o2[0]);
        });

        for (int i = 1, j = 1; i <= n; i++) {
            pqMinTop.add(new int[] {i, nums[i - 1]});
            pqMaxTop.add(new int[] {i, nums[i - 1]});

            while (pqMaxTop.peek()[1] - pqMinTop.peek()[1] > k) {
                j = Math.min(pqMinTop.peek()[0], pqMaxTop.peek()[0]) + 1;

                while (pqMinTop.peek()[0] < j) {
                    pqMinTop.poll();
                }

                while (pqMaxTop.peek()[0] < j) {
                    pqMaxTop.poll();
                }
            }

            memo[i] = (memoPrefix[i - 1] - (j - 2 >= 0 ? memoPrefix[j - 2] : 0) + MOD) % MOD;
            memoPrefix[i] = (memoPrefix[i - 1] + memo[i]) % MOD;
        }

        return memo[n];
    }

}
