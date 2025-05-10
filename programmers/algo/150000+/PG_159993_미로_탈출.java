// Solve 2025-05-03
// Update 2025-05-08

import java.util.*;

class PG_159993_미로_탈출 {

    static class Point {
        int x, y, canEscape;

        Point(int x, int y, int canEscape) {
            this.x = x;
            this.y = y;
            this.canEscape = canEscape;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public int solution(String[] maps) {
        int n = maps.length;
        int m = maps[0].length();
        char[][] board = new char[n][m];
        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        boolean[][][] visited = new boolean[n][m][2];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                board[x][y] = maps[x].charAt(y);

                if (board[x][y] == 'S') {
                    bfsQue.addLast(new Point(x, y, 0));
                    visited[x][y][0] = true;
                }
            }
        }

        int dist = 0;

        while (!bfsQue.isEmpty()) {
            dist++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point curPos = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = curPos.x + dx[d];
                    int ny = curPos.y + dy[d];

                    if (!isInRange(n, m, nx, ny)) continue;

                    int nxtCanEscape = (board[nx][ny] == 'L' ? 1 : curPos.canEscape);

                    if (nxtCanEscape == 1 && board[nx][ny] == 'E') {
                        return dist;
                    }

                    if (visited[nx][ny][nxtCanEscape] || board[nx][ny] == 'X') continue;

                    visited[nx][ny][nxtCanEscape] = true;
                    bfsQue.addLast(new Point(nx, ny, nxtCanEscape));
                }
            }
        }

        return -1;
    }

    static boolean isInRange(int n, int m, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

}
