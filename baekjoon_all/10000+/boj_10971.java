// Solve 2024-02-29
// Update 2026-01-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_10971 {

    static int n;
    static int[][] w;
    static int mn;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        w = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < n; j++) {
                w[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        mn = Integer.MAX_VALUE;
        recur(0, 1, 0);
        System.out.println(mn);
    }

    static void recur(int cur, int selected, int dist) {
        if (selected == (1 << n) - 1) {
            if (w[cur][0] != 0) {
                mn = Math.min(mn, dist + w[cur][0]);
            }

            return;
        }

        for (int i = 0; i < n; i++) {
            if ((selected & (1 << i)) != 0) continue;
            if (w[cur][i] == 0) continue;

            recur(i, selected | (1 << i), dist + w[cur][i]);
        }
    }

}
