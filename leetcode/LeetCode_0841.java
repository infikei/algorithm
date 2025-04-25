// Solve 2025-04-23

// BFS 풀이

import java.util.*;

class LeetCode_0841 {

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()];

        bfs(rooms, visited, 0);

        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    void bfs(List<List<Integer>> rooms, boolean[] visited, int start) {
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

        visited[start] = true;
        bfsQue.addLast(start);

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.pollFirst();

            for (int nxt : rooms.get(cur)) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    bfsQue.addLast(nxt);
                }
            }
        }
    }

}
