// Solve 2024-04-04

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_5643 {

    static int n, m;
    static int[][] adjMat;
    static int cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            n = Integer.parseInt(br.readLine());
            m = Integer.parseInt(br.readLine());
            adjMat = new int[n + 1][n + 1];

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                adjMat[a][b] = 1;
                adjMat[b][a] = -1;
            }

            int ans = 0;

            for (int u = 1; u <= n; u++) {
                cnt = 0;
                dfs(u, new boolean[n + 1], 1);
                dfs(u, new boolean[n + 1], -1);

                if (cnt == n - 1) {
                    ans++;
                }
            }

            sb.append("#").append(ti).append(" ").append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static void dfs(int u, boolean[] visited, int direction) {
        for (int nu = 1; nu <= n; nu++) {
            if (!visited[nu] && adjMat[u][nu] == direction) {
                visited[nu] = true;
                cnt++;
                dfs(nu, visited, direction);
            }
        }
    }

}
