// Solve 2026-06-11

import java.util.*;

class LC_2161 {

    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] result = new int[n];
        int pos = 0;
        int equalCnt = 0;
        ArrayList<Integer> right = new ArrayList<>();

        for (int num : nums) {
            if (num < pivot) {
                result[pos] = num;
                pos++;
            } else if (num > pivot) {
                right.add(num);
            } else {
                equalCnt++;
            }
        }

        while (equalCnt > 0) {
            result[pos] = pivot;
            pos++;
            equalCnt--;
        }

        for (int num : right) {
            result[pos] = num;
            pos++;
        }

        return result;
    }

}