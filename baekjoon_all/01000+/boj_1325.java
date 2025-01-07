// Solve 2024-03-06
// Update 2025-01-06

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1325 {

    private static int n;
    private static ArrayList<Integer>[] adj;
    private static boolean[] visited;
    private static int[] hackCount;
    private static ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n + 1];

        for (int u = 1; u <= n; u++) {
            adj[u] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[b].add(a);
        }

        visited = new boolean[n + 1];
        hackCount = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            hackCount[u] = bfs(u);
        }

        int maxHackCount = 0;

        for (int u = 1; u <= n; u++) {
            maxHackCount = Math.max(maxHackCount, hackCount[u]);
        }

        StringBuilder sb = new StringBuilder();

        for (int u = 1; u <= n; u++) {
            if (hackCount[u] == maxHackCount) {
                sb.append(u).append(" ");
            }
        }

        System.out.println(sb);
    }

    private static int bfs(int u) {
        for (int u2 = 1; u2 <= n; u2++) {
            visited[u2] = false;
        }

        visited[u] = true;
        bfsQue.add(u);
        int hacked = 1;

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.poll();

            for (int nxt : adj[cur]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    bfsQue.add(nxt);
                    hacked++;
                }
            }
        }

        return hacked;
    }

}
