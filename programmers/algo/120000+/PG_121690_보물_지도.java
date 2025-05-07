// Solve 2025-05-04

import java.util.*;

class PG_121690_보물_지도 {

    static class Point {
        int x, y, jumpedCnt;

        Point(int x, int y, int jumpedCnt) {
            this.x = x;
            this.y = y;
            this.jumpedCnt = jumpedCnt;
        }
    }

    static int[] dx = { -1, 0, 0, 1 };
    static int[] dy = { 0, -1, 1, 0 };
    static int[] dx2 = { -2, 0, 0, 2 };
    static int[] dy2 = { 0, -2, 2, 0 };

    public int solution(int n, int m, int[][] hole) {
        int[][] board = new int[n][m];

        for (int[] h : hole) {
            board[h[0] - 1][h[1] - 1] = 1;
        }

        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        boolean[][][] visited = new boolean[n][m][2];
        visited[0][0][0] = true;
        bfsQue.addLast(new Point(0, 0, 0));
        int movedTime = 0;

        while (!bfsQue.isEmpty()) {
            movedTime++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point curPos = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = curPos.x + dx[d];
                    int ny = curPos.y + dy[d];
                    int nxtJumpedCnt = curPos.jumpedCnt;

                    if (!isInRange(n, m, nx, ny) || board[nx][ny] == 1 || visited[nx][ny][nxtJumpedCnt]) continue;

                    if (nx == n - 1 && ny == m - 1) {
                        return movedTime;
                    }

                    visited[nx][ny][nxtJumpedCnt] = true;
                    bfsQue.addLast(new Point(nx, ny, nxtJumpedCnt));
                }

                if (curPos.jumpedCnt == 1) continue;

                for (int d = 0; d < 4; d++) {
                    int nx = curPos.x + dx2[d];
                    int ny = curPos.y + dy2[d];
                    int nxtJumpedCnt = curPos.jumpedCnt + 1;

                    if (!isInRange(n, m, nx, ny) || board[nx][ny] == 1 || visited[nx][ny][nxtJumpedCnt]) continue;

                    if (nx == n - 1 && ny == m - 1) {
                        return movedTime;
                    }

                    visited[nx][ny][nxtJumpedCnt] = true;
                    bfsQue.addLast(new Point(nx, ny, nxtJumpedCnt));
                }
            }
        }

        return -1;
    }

    boolean isInRange(int n, int m, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

}
