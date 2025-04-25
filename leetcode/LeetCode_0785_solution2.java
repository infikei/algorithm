// Solve 2025-04-24

// DFS 풀이

class LeetCode_0785_solution2 {

    public boolean isBipartite(int[][] graph) {
        int[] team = new int[graph.length];

        for (int u = 0; u < graph.length; u++) {
            if (team[u] != 0) continue;

            team[u] = 1;

            if (!dfs(graph, team, u)) {
                return false;
            }
        }

        return true;
    }

    boolean dfs(int[][] graph, int[] team, int cur) {
        for (int nxt : graph[cur]) {
            if (team[nxt] == 0) {
                team[nxt] = 3 - team[cur];

                if (!dfs(graph, team, nxt)) {
                    return false;
                }
            } else if (team[nxt] == team[cur]) {
                return false;
            }
        }

        return true;
    }

}
