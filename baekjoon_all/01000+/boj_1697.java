// Solve 2025-05-23

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_1697 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        System.out.println(bfs(n, k));
    }

    static int bfs(int n, int k) {
        if (n == k) return 0;

        boolean[] visited = new boolean[100001];
        ArrayDeque<Integer> bfsQue = new ArrayDeque<>();
        visited[n] = true;
        bfsQue.addLast(n);
        int dist = 0;

        while (!bfsQue.isEmpty()) {
            dist++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                int cur = bfsQue.pollFirst();

                if (cur * 2 <= 100000 && !visited[cur * 2]) {
                    if (cur * 2 == k) return dist;

                    visited[cur * 2] = true;
                    bfsQue.addLast(cur * 2);
                }

                if (cur + 1 <= 100000 && !visited[cur + 1]) {
                    if (cur + 1 == k) return dist;

                    visited[cur + 1] = true;
                    bfsQue.addLast(cur + 1);
                }

                if (cur >= 1 && !visited[cur - 1]) {
                    if (cur - 1 == k) return dist;

                    visited[cur - 1] = true;
                    bfsQue.addLast(cur - 1);
                }
            }
        }

        return -1;
    }

}
