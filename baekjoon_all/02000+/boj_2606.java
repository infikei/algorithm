// Solve 2024-02-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_2606 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] adj = new ArrayList[n + 1];

        for (int u = 1; u <= n; u++) {
            adj[u] = new ArrayList<Integer>();
        }

        while (k-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            adj[from].add(to);
            adj[to].add(from);
        }

        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
        boolean[] visited = new boolean[n + 1];
        bfsQue.offer(1);
        visited[1] = true;
        int bfsCount = 0;

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.poll();

            for (int next : adj[cur]) {
                if (visited[next]) continue;

                visited[next] = true;
                bfsQue.offer(next);
                bfsCount++;
            }
        }

        System.out.println(bfsCount);
        br.close();
    }

}
