// Solve 2026-05-16

import java.util.*;

class LC_2784 {

    public boolean isGood(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }

        return nums[n - 1] == n - 1;
    }

}
