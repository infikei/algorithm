// Solve 2025-04-24

// BFS 풀이

import java.util.*;

class LeetCode_0785 {

    public boolean isBipartite(int[][] graph) {
        int[] team = new int[graph.length];

        for (int u = 0; u < graph.length; u++) {
            if (team[u] != 0) continue;

            if (!bfs(graph, team, u)) {
                return false;
            }
        }

        return true;
    }

    boolean bfs(int[][] graph, int[] team, int start) {
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

        team[start] = 1;
        bfsQue.addLast(start);

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.pollFirst();

            for (int nxt : graph[cur]) {
                if (team[nxt] == 0) {
                    team[nxt] = 3 - team[cur];
                    bfsQue.addLast(nxt);
                    continue;
                }

                if (team[nxt] == team[cur]) {
                    return false;
                }
            }
        }

        return true;
    }

}
