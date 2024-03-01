// Solve 2024-02-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_10971 {

    static int n;
    static int[][] adj;
    static int minDist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        adj = new int[n][n];

        for (int from = 0; from < n; from++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int to = 0; to < n; to++) {
                adj[from][to] = Integer.parseInt(st.nextToken());
            }
        }

        minDist = Integer.MAX_VALUE;
        recur(1, 0, 0, 0);
        System.out.println(minDist);
        br.close();
    }

    static void recur(int depth, int selected, int prev, int dist) {
        if (depth == n) {
            if (adj[prev][0] != 0) {
                minDist = Math.min(minDist, dist + adj[prev][0]);
            }

            return;
        }

        if (dist > minDist) return;

        for (int u = 1; u < n; u++) {
            if ((selected & 1 << u) == 0 && adj[prev][u] != 0) {
                recur(depth + 1, selected | 1 << u, u, dist + adj[prev][u]);
            }
        }
    }

}
