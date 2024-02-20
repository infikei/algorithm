// Solve 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_2252 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        int[] inDegree = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            adj[u] = new ArrayList<Integer>();
        }
        
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            adj[from].add(to);
            inDegree[to]++;
        }

        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
        StringBuilder sb = new StringBuilder();

        for (int u = 1; u <= n; u++) {
            if (inDegree[u] == 0) {
                bfsQue.offer(u);
            }
        }

        while (n-- > 0) {
            int cur = bfsQue.poll();
            sb.append(cur).append(" ");

            for (int next : adj[cur]) {
                if (--inDegree[next] == 0) {
                    bfsQue.offer(next);
                }
            }
        }

        System.out.println(sb);
        br.close();
    }

}
