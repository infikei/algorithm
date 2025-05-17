// Solve 2025-05-15

import java.util.*;

class PG_86971_전력망을_둘로_나누기 {

    public int solution(int n, int[][] wires) {
        List<List<Integer>> adj = convertToAdjList(n, wires);
        int[] cnt = new int[n + 1];

        dfs(1, 0, adj, cnt);

        int result = n;

        for (int u = 1; u <= n; u++) {
            result = Math.min(result, Math.abs(n - cnt[u] * 2));
        }

        return result;
    }

    List<List<Integer>> convertToAdjList(int n, int[][] wires) {
        List<List<Integer>> adj = new ArrayList<>();

        for (int u = 0; u <= n; u++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int[] wire : wires) {
            adj.get(wire[0]).add(wire[1]);
            adj.get(wire[1]).add(wire[0]);
        }

        return adj;
    }

    int dfs(int cur, int par, List<List<Integer>> adj, int[] cnt) {
        int result = 1;

        for (int nxt : adj.get(cur)) {
            if (nxt == par) continue;

            result += dfs(nxt, cur, adj, cnt);
        }

        return cnt[cur] = result;
    }

}
