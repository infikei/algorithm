// Solve 2025-12-10

import java.util.*;

class LeetCode_3583 {

    public int specialTriplets(int[] nums) {
        final int MOD = 1000000007;

        List<List<Integer>> indexList = new ArrayList<>();

        for (int i = 0; i <= 100000; i++) {
            indexList.add(new ArrayList<>());
        }

        for (int i = 0; i < nums.length; i++) {
            indexList.get(nums[i]).add(i);
        }

        int ret = 0;

        for (int i = 0; i < nums.length; i++) {
            int v2 = nums[i] * 2;

            if (v2 > 100000) continue;

            long right = indexList.get(v2).size() - getUpperBound(indexList.get(v2), i);
            long left = getLowerBound(indexList.get(v2), i);
            ret += left * right % MOD;
            ret %= MOD;
        }

        return ret;
    }

    int getLowerBound(List<Integer> list, int val) {
        int low = 0;
        int high = list.size() - 1;
        int mn = list.size();

        while (low <= high) {
            int mid = (low + high) / 2;

            if (list.get(mid) >= val) {
                mn = Math.min(mn, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return mn;
    }

    int getUpperBound(List<Integer> list, int val) {
        int low = 0;
        int high = list.size() - 1;
        int mn = list.size();

        while (low <= high) {
            int mid = (low + high) / 2;

            if (list.get(mid) > val) {
                mn = Math.min(mn, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return mn;
    }

}
