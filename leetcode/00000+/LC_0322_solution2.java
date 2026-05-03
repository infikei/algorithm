// Solve 2025-04-24

import java.util.*;

class LeetCode_0322_solution2 {

    public int coinChange(int[] coins, int amount) {
        final int INF = 1000000000;

        int[] memo = new int[amount + 1];
        Arrays.fill(memo, INF);
        memo[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    memo[i] = Math.min(memo[i], memo[i - coin] + 1);
                }
            }
        }

        return (memo[amount] >= INF ? -1 : memo[amount]);
    }

}
