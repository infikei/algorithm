// Solve 2025-06-11

import java.util.*;

class LeetCode_0046 {

    void recur(int depth, boolean[] selected, int[] curPermutation, List<List<Integer>> permutations, int[] nums) {
        if (depth == nums.length) {
            List<Integer> curList = new ArrayList<>();

            for (int num : curPermutation) {
                curList.add(num);
            }

            permutations.add(curList);
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (selected[i]) continue;

            selected[i] = true;
            curPermutation[depth] = nums[i];
            recur(depth + 1, selected, curPermutation, permutations, nums);
            selected[i] = false;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();
        int[] curPermutation = new int[nums.length];
        boolean[] selected = new boolean[nums.length];
        recur(0, selected, curPermutation, permutations, nums);
        return permutations;
    }

}
