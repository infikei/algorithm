// Solve 2025-06-11

import java.util.*;

class LeetCode_0077 {

    void recur(int depth, int from, int[] curCombination, List<List<Integer>> combinations, int n, int k) {
        if (depth == k) {
            List<Integer> curList = new ArrayList<>();

            for (int num : curCombination) {
                curList.add(num);
            }

            combinations.add(curList);
            return;
        }

        for (int i = from; i <= n; i++) {
            curCombination[depth] = i;
            recur(depth + 1, i + 1, curCombination, combinations, n, k);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinations = new ArrayList<>();
        int[] curCombination = new int[k];
        recur(0, 1, curCombination, combinations, n, k);
        return combinations;
    }

}
