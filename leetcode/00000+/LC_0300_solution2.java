// Solve 2025-06-15

import java.util.*;

class LeetCode_0300_solution2 {

    int getLowerBound(List<Integer> list, int target) {
        int low = -1;
        int high = list.size();

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (list.get(mid) >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        List<Integer> memo = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int pos = getLowerBound(memo, nums[i]);

            if (pos == memo.size()) {
                memo.add(nums[i]);
            } else {
                memo.set(pos, nums[i]);
            }
        }

        return memo.size();
    }

}
