// Solve 2025-04-23

import java.util.*;

class PG_49189_가장_먼_노드 {

    public int solution(int n, int[][] edge) {
        // 간선 리스트를 통해 인접 리스트를 만든다.
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int[] e : edge) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        // BFS를 수행한다.
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
        boolean[] visited = new boolean[n + 1];

        visited[1] = true;
        bfsQue.addLast(1);

        int cnt = 0;

        while (!bfsQue.isEmpty()) {
            cnt = bfsQue.size();
            int iter = bfsQue.size();

            while (iter-- > 0) {
                int cur = bfsQue.pollFirst();

                for (int nxt : adj.get(cur)) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        bfsQue.addLast(nxt);
                    }
                }
            }
        }

        return cnt;
    }

}
