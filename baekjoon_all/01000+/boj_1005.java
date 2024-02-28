// Solve 2024-02-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_1005 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine(), " ");
            int[] d = new int[n + 1];
            ArrayList<Integer>[] adjList = new ArrayList[n + 1];
            int[] inDegree = new int[n + 1];
            int[] ans = new int[n + 1];

            for (int u = 1; u <= n; u++) {
                d[u] = Integer.parseInt(st.nextToken());
            }

            for (int u = 1; u <= n; u++) {
                adjList[u] = new ArrayList<Integer>();
            }

            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                adjList[from].add(to);
                inDegree[to]++;
            }

            int w = Integer.parseInt(br.readLine());
            ArrayDeque<Integer> que = new ArrayDeque<Integer>();

            for (int u = 1; u <= n; u++) {
                if (inDegree[u] == 0) {
                    que.offer(u);
                    ans[u] = d[u];
                }
            }

            while (!que.isEmpty()) {
                int cur = que.poll();

                if (cur == w) break;

                for (int next : adjList[cur]) {
                    ans[next] = Math.max(ans[next], ans[cur] + d[next]);

                    if (--inDegree[next] == 0) {
                        que.offer(next);
                    }
                }
            }

            sb.append(ans[w]).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
