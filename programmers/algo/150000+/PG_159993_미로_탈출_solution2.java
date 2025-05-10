// Solve 2025-05-03
// Update 2025-05-08

import java.util.*;

class PG_159993_미로_탈출_solution2 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public int solution(String[] maps) {
        int n = maps.length;
        int m = maps[0].length();
        char[][] board = new char[n][m];
        Point start = new Point(0, 0);
        Point lever = new Point(0, 0);
        Point exit = new Point(0, 0);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                board[x][y] = maps[x].charAt(y);

                if (board[x][y] == 'S') {
                    start = new Point(x, y);
                } else if (board[x][y] == 'L') {
                    lever = new Point(x, y);
                } else if (board[x][y] == 'E') {
                    exit = new Point(x, y);
                }
            }
        }

        int startToLever = getMinDist(board, n, m, start, lever);
        int leverToExit = getMinDist(board, n, m, lever, exit);

        if (startToLever == -1 || leverToExit == -1) return -1;

        return startToLever + leverToExit;
    }

    static int getMinDist(char[][] board, int n, int m, Point from, Point to) {
        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        boolean[][] visited = new boolean[n][m];
        visited[from.x][from.y] = true;
        bfsQue.addLast(new Point(from.x, from.y));
        int dist = 0;

        while (!bfsQue.isEmpty()) {
            dist++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point curPos = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = curPos.x + dx[d];
                    int ny = curPos.y + dy[d];

                    if (nx == to.x && ny == to.y) return dist;

                    if (!isInRange(n, m, nx, ny) || visited[nx][ny] || board[nx][ny] == 'X') continue;

                    visited[nx][ny] = true;
                    bfsQue.addLast(new Point(nx, ny));
                }
            }
        }

        return -1;
    }

    static boolean isInRange(int n, int m, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

}
