// Solve 2026-08-23

import java.util.ArrayList;
import java.util.List;

class LC_3116 {

    long getGCD(long a, long b) {
        while (b > 0) {
            long r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    long getLCM(long a, long b) {
        return a / getGCD(a, b) * b;
    }

    void recur(int depth, int cnt, long lcm, int n, int[] coins, List<Long> lcmInclude, List<Long> lcmExclude) {
        if (depth == n) {
            if (cnt == 0) return;

            if (cnt % 2 == 1) {
                lcmInclude.add(lcm);
            } else {
                lcmExclude.add(lcm);
            }

            return;
        }

        recur(depth + 1, cnt, lcm, n, coins, lcmInclude, lcmExclude);
        recur(depth + 1, cnt + 1, getLCM(lcm, coins[depth]), n, coins, lcmInclude, lcmExclude);
    }

    public long findKthSmallest(int[] coins, int k) {
        int n = coins.length;
        List<Long> lcmInclude = new ArrayList<>();
        List<Long> lcmExclude = new ArrayList<>();

        recur(0, 0, 1, n, coins, lcmInclude, lcmExclude);

        long low = 0;
        long high = 50000000000L;
        long mn = high;

        while (low <= high) {
            long mid = (low + high) / 2;
            long cnt = 0;

            for (long lcm : lcmInclude) {
                cnt += mid / lcm;
            }

            for (long lcm : lcmExclude) {
                cnt -= mid / lcm;
            }

            if (cnt >= k) {
                mn = Math.min(mn, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return mn;
    }

}
