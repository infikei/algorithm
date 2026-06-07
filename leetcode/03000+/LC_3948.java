// Solve 2026-06-03

import java.util.*;

class LC_3948 {

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
        ArrayList<ArrayDeque<Integer>> queList = new ArrayList<>();

        for (int i = 0; i < 100002; i++) {
            queList.add(new ArrayDeque<Integer>());
        }

        for (int i = 0; i < n; i++) {
            queList.get(nums[i]).addLast(i);
        }

        ArrayDeque<Integer> que_0 = queList.get(0);
        ArrayList<Integer> result = new ArrayList<>();
        int prvLastIdx = -1;

        while (!que_0.isEmpty()) {
            int curLastIdx = queList.get(0).pollFirst();
            int mex = 1;

            for (int v = 1; v < 100002; v++) {
                ArrayDeque<Integer> que_v = queList.get(v);

                while (!que_v.isEmpty() && que_v.getFirst() <= prvLastIdx) {
                    que_v.pollFirst();
                }

                if (que_v.isEmpty()) {
                    mex = v;
                    break;
                }

                curLastIdx = Math.max(curLastIdx, que_v.pollFirst());
            }

            result.add(mex);
            prvLastIdx = curLastIdx;

            while (!que_0.isEmpty() && que_0.getFirst() <= prvLastIdx) {
                que_0.pollFirst();
            }
        }

        for (int i = prvLastIdx + 1; i < n; i++) {
            result.add(0);
        }

        return convertToArray(result);
    }
}
