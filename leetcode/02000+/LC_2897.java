// Solve 2026-10-12

import java.util.*;

class LC_2897 {
    public int maxSum(List<Integer> nums, int k) {
        final long MOD = 1000000007;
        int[] cnt = new int[30];

        for (int num : nums) {
            for (int i = 0; i < 30; i++) {
                if (num % 2 == 1) {
                    cnt[i]++;
                }

                num /= 2;
            }
        }

        long ans = 0;

        for (int i = 0; i < k; i++) {
            int num = 0;

            for (int j = 0; j < 30; j++) {
                if (cnt[j] >= 1) {
                    cnt[j]--;
                    num |= (1 << j);
                }
            }

            ans = (ans + (long) num * num % MOD) % MOD;
        }

        return (int) ans;
    }
}
