// Solve 2025-04-16

import java.util.*;

class LeetCode_0001_solution2 {

    public int[] twoSum(int[] nums, int target) {
        int[][] numsAndIndices = new int[nums.length][2];

        for (int i = 0; i < nums.length; i++) {
            numsAndIndices[i][0] = nums[i];
            numsAndIndices[i][1] = i;
        }

        Arrays.sort(numsAndIndices, (o1, o2) -> (o1[0] - o2[0]));
        int i = 0;
        int j = nums.length - 1;

        while (i < j) {
            int sum = numsAndIndices[i][0] + numsAndIndices[j][0];

            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return new int[] { numsAndIndices[i][1], numsAndIndices[j][1] };
            }
        }

        return null;
    }

}
