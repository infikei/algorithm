// Solve 2025-04-24

import java.util.*;

class LeetCode_0322 {

    public int coinChange(int[] coins, int amount) {
        if (amount == 0) return 0;

        boolean[] visited = new boolean[amount + 1];
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

        visited[0] = true;
        bfsQue.addLast(0);

        int depth = 0;

        while (!bfsQue.isEmpty()) {
            depth++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                int cur = bfsQue.pollFirst();

                for (int coin : coins) {
                    int nxt = cur + coin;

                    if (nxt == amount) {
                        return depth;
                    }

                    if (nxt <= amount && !visited[nxt]) {
                        visited[nxt] = true;
                        bfsQue.addLast(nxt);
                    }
                }
            }
        }

        return -1;
    }

}
