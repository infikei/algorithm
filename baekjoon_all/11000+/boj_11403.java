// Solve 2024-02-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_11403 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[][] adj = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < n; j++) {
                adj[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int mid = 0; mid < n; mid++) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    adj[from][to] |= (adj[from][mid] & adj[mid][to]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(adj[i][j]).append(" ");
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
