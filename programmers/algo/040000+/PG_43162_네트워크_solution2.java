// Solve 2025-04-23

// DFS 풀이

class PG_43162_네트워크_solution2 {

    public int solution(int n, int[][] computers) {
        int componentCnt = 0;
        boolean[] visited = new boolean[n];

        for (int u = 0; u < n; u++) {
            if (visited[u]) continue;

            componentCnt++;
            dfs(n, computers, visited, u);
        }

        return componentCnt;
    }

    void dfs(int n, int[][] computers, boolean[] visited, int cur) {
        visited[cur] = true;

        for (int nxt = 0; nxt < n; nxt++) {
            if (computers[cur][nxt] == 1 && !visited[nxt]) {
                dfs(n, computers, visited, nxt);
            }
        }
    }

}
