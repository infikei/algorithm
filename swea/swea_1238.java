// Solve 2024-02-22

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class swea_1238 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        ArrayList<Integer>[] adj = new ArrayList[101];
        boolean[] visited = new boolean[101];

        for (int u = 1; u <= 100; u++) {
            adj[u] = new ArrayList<Integer>();
        }

        for (int ti = 1; ti <= 10; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int startNode = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine(), " ");

            for (int u = 1; u <= 100; u++) {
                adj[u].clear();
                visited[u] = false;
            }

            for (int i = 0; i < n; i += 2) {
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                adj[from].add(to);
            }

            ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
            int finalMaxNode = 0;
            visited[startNode] = true;
            bfsQue.offer(startNode);

            while (!bfsQue.isEmpty()) {
                int curIter = bfsQue.size();
                finalMaxNode = 0;

                while (curIter-- > 0) {
                    int curNode = bfsQue.poll();
                    finalMaxNode = Math.max(finalMaxNode, curNode);

                    for (int nextNode : adj[curNode]) {
                        if (visited[nextNode]) continue;

                        visited[nextNode] = true;
                        bfsQue.offer(nextNode);
                    }
                }
            }

            sb.append("#").append(ti).append(" ").append(finalMaxNode).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
