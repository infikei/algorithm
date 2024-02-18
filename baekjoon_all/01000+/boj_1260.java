// Solve 2024-02-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_1260 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int startNode = Integer.parseInt(st.nextToken());

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

        for (int u = 1; u <= n; u++) {
            Collections.sort(adj[u]);
        }

        boolean[] visited = new boolean[n + 1];
        ArrayDeque<int[]> dfsStack = new ArrayDeque<int[]>();
        visited[startNode] = true;
        sb.append(startNode).append(" ");
        dfsStack.offerLast(new int[] { startNode, 0 });

        while (!dfsStack.isEmpty()) {
            int[] cur = dfsStack.pollLast();

            for (int i = cur[1]; i < adj[cur[0]].size(); i++) {
                int nextNode = adj[cur[0]].get(i);

                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    sb.append(nextNode).append(" ");
                    dfsStack.add(new int[] { cur[0], i + 1 });
                    dfsStack.add(new int[] { nextNode, 0 });
                    break;
                }
            }
        }

        sb.append("\n");

        for (int u = 1; u <= n; u++) {
            visited[u] = false;
        }

        ArrayDeque<Integer> bfsQueue = new ArrayDeque<Integer>();
        visited[startNode] = true;
        bfsQueue.offerLast(startNode);

        while (!bfsQueue.isEmpty()) {
            int curNode = bfsQueue.pollFirst();
            sb.append(curNode).append(" ");

            for (int nextNode : adj[curNode]) {
                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    bfsQueue.offerLast(nextNode);
                }
            }
        }

        sb.append("\n");
        System.out.print(sb);
        br.close();
    }

}
