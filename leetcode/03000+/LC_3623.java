// Solve 2025-12-03

import java.util.*;

class LeetCode_3623 {

    public int countTrapezoids(int[][] points) {
        Map<Integer, Integer> yCounter = new HashMap<>();

        for (int[] point : points) {
            int y = point[1];
            yCounter.put(y, yCounter.getOrDefault(y, 0) + 1);
        }

        final long MOD = 1000000007;
        long ans = 0;
        long prv = 0;

        for (int v : yCounter.values()) {
            long cur = v * (long) (v - 1) / 2 % MOD;
            ans = (ans + prv * cur) % MOD;
            prv = (prv + cur) % MOD;
        }

        return (int) ans;
    }

}
