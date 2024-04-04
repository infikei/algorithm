// Solve 2024-04-04

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2458_floyd_warshall {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] adjMat = new int[n + 1][n + 1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adjMat[a][b] = 1;
        }

        for (int mid = 1; mid <= n; mid++) {
            for (int from = 1; from <= n; from++) {
                if (from == mid || adjMat[from][mid] == 0) continue;

                for (int to = 1; to <= n; to++) {
                    if (adjMat[from][to] == 1) continue;

                    adjMat[from][to] = adjMat[from][mid] & adjMat[mid][to];
                }
            }
        }

        int ans = 0;

        for (int u = 1; u <= n; u++) {
            int cnt = 0;

            for (int nu = 1; nu <= n; nu++) {
                cnt += adjMat[u][nu] + adjMat[nu][u];
            }

            if (cnt == n - 1) {
                ans++;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
