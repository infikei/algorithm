// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_26169 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int[][] board;
    static int ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        board = new int[5][5];

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < 5; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine(), " ");
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        dfs(0, x, y, board[x][y]);

        System.out.println(ans);
        br.close();
    }

    static void dfs(int depth, int x, int y, int appleCnt) {
        if (depth == 3) {
            if (appleCnt >= 2) {
                ans = 1;
            }

            return;
        }

        int curBoard = board[x][y];
        board[x][y] = -1;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (board[nx][ny] == -1) continue;

            dfs(depth + 1, nx, ny, appleCnt + board[nx][ny]);
        }

        board[x][y] = curBoard;
    }

}
