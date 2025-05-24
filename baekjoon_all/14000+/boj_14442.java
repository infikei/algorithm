// Solve 2025-05-23

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_14442 {

    static class Position {
        int x;
        int y;
        int wallCnt;

        Position(int x, int y, int wallCnt) {
            this.x = x;
            this.y = y;
            this.wallCnt = wallCnt;
        }
    }

    static int[] dx = { -1, 0, 0, 1 };
    static int[] dy = { 0, -1, 1, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < m; y++) {
                board[x][y] = row.charAt(y) - '0';
            }
        }

        System.out.println(bfs(n, m, k, board));
    }

    static int bfs(int n, int m, int k, int[][] board) {
        boolean[][][] visited = new boolean[k + 1][n][m];
        ArrayDeque<Position> bfsQue = new ArrayDeque<>();
        bfsQue.addLast(new Position(-1, 0, 0));
        int dist = 0;

        while (!bfsQue.isEmpty()) {
            int iter = bfsQue.size();
            dist++;

            while (iter-- > 0) {
                Position curPos = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = curPos.x + dx[d];
                    int ny = curPos.y + dy[d];

                    if (!isInBoard(nx, ny, n, m)) continue;

                    int nxtWallCnt = (board[nx][ny] == 1 ? (curPos.wallCnt + 1) : curPos.wallCnt);

                    if (nxtWallCnt > k || visited[nxtWallCnt][nx][ny]) continue;
                    if (nx == n - 1 && ny == m - 1) return dist;

                    visited[nxtWallCnt][nx][ny] = true;
                    bfsQue.addLast(new Position(nx, ny, nxtWallCnt));
                }
            }
        }

        return -1;
    }

    static boolean isInBoard(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

}
