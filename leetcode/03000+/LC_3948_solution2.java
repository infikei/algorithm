// Solve 2026-06-03

import java.util.*;

class LC_3948_solution2 {

    int[] convertToArray(ArrayList<Integer> list) {
        int n = list.size();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = list.get(i);
        }

        return arr;
    }

    public int[] maximumMEX(int[] nums) {
        int n = nums.length;
        TreeMap<Integer, Integer> totalCounts = new TreeMap<>();

        for (int num : nums) {
            totalCounts.put(num, totalCounts.getOrDefault(num, 0) + 1);
        }

        ArrayList<Integer> result = new ArrayList<>();
        int i = 0;

        while (i < n) {
            int mex = 0;

            while (totalCounts.containsKey(mex)) {
                mex++;
            }

            if (mex == 0) {
                while (i < n) {
                    result.add(0);
                    i++;
                }

                break;
            }

            result.add(mex);
            TreeSet<Integer> numsLessThanMEX = new TreeSet<>();

            while (true) {
                totalCounts.put(nums[i], totalCounts.get(nums[i]) - 1);

                if (totalCounts.get(nums[i]) == 0) {
                    totalCounts.remove(nums[i]);
                }

                if (nums[i] < mex) {
                    numsLessThanMEX.add(nums[i]);
                }

                i++;

                if (numsLessThanMEX.size() == mex) {
                    break;
                }
            }
        }

        return convertToArray(result);
    }
}
