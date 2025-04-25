// Solve 2025-04-23

// BFS 풀이

import java.util.*;

class PG_43162_네트워크 {

    public int solution(int n, int[][] computers) {
        int componentCnt = 0;
        boolean[] visited = new boolean[n];

        for (int u = 0; u < n; u++) {
            if (visited[u]) continue;

            componentCnt++;
            bfs(n, computers, visited, u);
        }

        return componentCnt;
    }

    void bfs(int n, int[][] computers, boolean[] visited, int start) {
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

        visited[start] = true;
        bfsQue.addLast(start);

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.pollFirst();

            for (int nxt = 0; nxt < n; nxt++) {
                if (!visited[nxt] && computers[cur][nxt] == 1) {
                    visited[nxt] = true;
                    bfsQue.addLast(nxt);
                }
            }
        }
    }

}
