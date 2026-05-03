// Solve 2025-04-23

// DFS 풀이

import java.util.*;

class LeetCode_0841_solution2 {

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()];

        dfs(rooms, visited, 0);

        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    void dfs(List<List<Integer>> rooms, boolean[] visited, int cur) {
        visited[cur] = true;

        for (int nxt : rooms.get(cur)) {
            if (!visited[nxt]) {
                dfs(rooms, visited, nxt);
            }
        }
    }

}
