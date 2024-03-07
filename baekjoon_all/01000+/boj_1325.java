// Solve 2024-03-06

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1325 {

    private static int[] hackCount = new int[10001];
    private static boolean[] visited = new boolean[10001];
    private static ArrayList<Integer>[] adj = new ArrayList[10001];
    private static ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int u = 1; u <= n; u++) {
            adj[u] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
        }

        for (int u = 1; u <= n; u++) {
            for (int u2 = 1; u2 <= n; u2++) {
                visited[u2] = false;
            }

            bfs(u);
        }

        int maxHackCount = 0;

        for (int u = 1; u <= n; u++) {
            if (maxHackCount < hackCount[u]) {
                maxHackCount = hackCount[u];
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int u = 1; u <= n; u++) {
            if (hackCount[u] == maxHackCount) {
                sb.append(u).append(" ");
            }
        }

        System.out.println(sb);
    }

    private static void bfs(int u) {
        visited[u] = true;
        bfsQue.add(u);

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.poll();

            for (int next : adj[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    hackCount[next]++;
                    bfsQue.add(next);
                }
            }
        }
    }

}
