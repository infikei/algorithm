// Solve 2025-06-11

import java.util.*;

class LeetCode_0046_solution2 {

    void recur(boolean[] selected, List<Integer> curPermutation, List<List<Integer>> permutations, int[] nums) {
        if (curPermutation.size() == nums.length) {
            permutations.add(new ArrayList<>(curPermutation));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (selected[i]) continue;

            selected[i] = true;
            curPermutation.add(nums[i]);
            recur(selected, curPermutation, permutations, nums);
            curPermutation.remove(curPermutation.size() - 1);
            selected[i] = false;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();
        List<Integer> curPermutation = new ArrayList<>();
        boolean[] selected = new boolean[nums.length];
        recur(selected, curPermutation, permutations, nums);
        return permutations;
    }

}
