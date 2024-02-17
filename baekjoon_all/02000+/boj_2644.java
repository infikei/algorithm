// Solve 2024-02-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_2644 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int u1 = Integer.parseInt(st.nextToken());
        int u2 = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] adj = new ArrayList[n + 1];

        for (int u = 1; u <= n; u++) {
            adj[u] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            adj[from].add(to);
            adj[to].add(from);
        }

        System.out.println(bfs(adj, n, u1, u2));
        br.close();
    }

    static int bfs(ArrayList<Integer>[] adj, int n, int u1, int u2) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> bfsQue = new ArrayDeque<Integer>();
        visited[u1] = true;
        bfsQue.offer(u1);
        int curDepth = 0;

        while (!bfsQue.isEmpty()) {
            curDepth++;
            int curIter = bfsQue.size();

            while (curIter-- > 0) {
                int curNode = bfsQue.poll();

                for (int nextNode : adj[curNode]) {
                    if (nextNode == u2) {
                        return curDepth;
                    }

                    if (!visited[nextNode]) {
                        visited[nextNode] = true;
                        bfsQue.offer(nextNode);
                    }
                }
            }
        }

        return -1;
    }

}
