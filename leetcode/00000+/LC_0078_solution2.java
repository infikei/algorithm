// Solve 2025-06-11
// Update 2026-05-09

import java.util.*;

class LC_0078_solution2 {

    void recur(int depth, List<Integer> curSubset, List<List<Integer>> subsets, int[] nums) {
        if (depth == nums.length) {
            subsets.add(new ArrayList<>(curSubset));
            return;
        }

        curSubset.add(nums[depth]);
        recur(depth + 1, curSubset, subsets, nums);
        curSubset.remove(curSubset.size() - 1);

        recur(depth + 1, curSubset, subsets, nums);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> curSubset = new ArrayList<>();
        recur(0, curSubset, subsets, nums);
        return subsets;
    }

}
