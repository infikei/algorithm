// Solve 2025-06-11

import java.util.*;

public class LeetCode_0078 {

    void recur(int depth, boolean[] selected, List<List<Integer>> subsets, int[] nums) {
        if (depth == nums.length) {
            List<Integer> curSubset = new ArrayList<>();

            for (int i = 0; i < selected.length; i++) {
                if (selected[i]) {
                    curSubset.add(nums[i]);
                }
            }

            subsets.add(curSubset);
            return;
        }

        selected[depth] = true;
        recur(depth + 1, selected, subsets, nums);
        selected[depth] = false;

        recur(depth + 1, selected, subsets, nums);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        boolean[] selected = new boolean[nums.length];
        recur(0, selected, subsets, nums);
        return subsets;
    }

}
