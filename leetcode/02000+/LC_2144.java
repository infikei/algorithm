// Solve 2026-06-03

import java.util.*;

class LC_2144 {

    void reverse(int[] arr) {
        int n = arr.length;

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    public int minimumCost(int[] cost) {
        int n = cost.length;
        int sum = 0;

        Arrays.sort(cost);
        reverse(cost);

        for (int i = 0; i < n; i++) {
            if (i % 3 == 2) continue;

            sum += cost[i];
        }

        return sum;
    }
}
