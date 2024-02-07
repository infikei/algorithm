// Solve 2024-02-07

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_16927 {

    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        int[][] board = new int[n][m];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] ans = new int[n][m];
        int depth = 0;
        int blockCnt = (n + m - 2) * 2;

        while (ans[depth][depth] == 0) {
            int ansX = depth;
            int ansY = depth;
            int ansD = 0;
            int iter = r % blockCnt;

            while (iter-- > 0) {
                int ansNx = ansX + dx[ansD];
                int ansNy = ansY + dy[ansD];

                if (ansNx < depth || ansNx >= n - depth || ansNy < depth || ansNy >= m - depth) {
                    if (++ansD == 4) ansD = 0;

                    ansNx = ansX + dx[ansD];
                    ansNy = ansY + dy[ansD];
                }

                ansX = ansNx;
                ansY = ansNy;
            }

            int boardX = depth;
            int boardY = depth;
            int boardD = 0;
            iter = blockCnt;

            while (iter-- > 0) {
                int ansNx = ansX + dx[ansD];
                int ansNy = ansY + dy[ansD];

                if (ansNx < depth || ansNx >= n - depth || ansNy < depth || ansNy >= m - depth) {
                    if (++ansD == 4) ansD = 0;

                    ansNx = ansX + dx[ansD];
                    ansNy = ansY + dy[ansD];
                }

                int boardNx = boardX + dx[boardD];
                int boardNy = boardY + dy[boardD];

                if (boardNx < depth || boardNx >= n - depth || boardNy < depth || boardNy >= m - depth) {
                    if (++boardD == 4) boardD = 0;

                    boardNx = boardX + dx[boardD];
                    boardNy = boardY + dy[boardD];
                }

                ansX = ansNx;
                ansY = ansNy;
                boardX = boardNx;
                boardY = boardNy;

                ans[ansX][ansY] = board[boardX][boardY];
            }

            blockCnt -= 8;
            depth++;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(ans[i][j]).append(" ");
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
