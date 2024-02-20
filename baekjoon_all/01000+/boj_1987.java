// Solve 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1987 {

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int n, m;
    static int[][] board;
    static int maxDepth;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n][m];

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < m; y++) {
                board[x][y] = row.charAt(y) - '0';
            }
        }

        dfs(0, 0, 1, 1 << board[0][0]);
        System.out.println(maxDepth);
        br.close();
    }

    static void dfs(int x, int y, int depth, int selected) {
        if (depth > maxDepth) {
            maxDepth = depth;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (selected & 1 << board[nx][ny]) == 0) {
                dfs(nx, ny, depth + 1, selected | 1 << board[nx][ny]);
            }
        }
    }

}
