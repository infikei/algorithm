// Solve 2025-06-11

import java.util.*;

class LeetCode_0077_solution2 {

    void recur(int depth, int from, List<Integer> curCombination, List<List<Integer>> combinations, int n, int k) {
        if (depth == k) {
            combinations.add(new ArrayList<>(curCombination));
            return;
        }

        for (int i = from; i <= n; i++) {
            curCombination.add(i);
            recur(depth + 1, i + 1, curCombination, combinations, n, k);
            curCombination.remove(curCombination.size() - 1);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinations = new ArrayList<>();
        List<Integer> curCombination = new ArrayList<>();
        recur(0, 1, curCombination, combinations, n, k);
        return combinations;
    }

}
