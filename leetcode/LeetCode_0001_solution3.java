// Solve 2025-04-16

import java.util.*;

class LeetCode_0001_solution3 {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                return new int[] { map.get(target - nums[i]), i };
            }

            map.put(nums[i], i);
        }

        return null;
    }

}
