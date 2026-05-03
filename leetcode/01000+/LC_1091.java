// Solve 2025-05-03

import java.util.*;

class LeetCode_1091 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;

        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        bfsQue.addLast(new Point(-1, -1));
        int depth = 0;

        while (!bfsQue.isEmpty()) {
            int iter = bfsQue.size();
            depth++;

            while (iter-- > 0) {
                Point cur = bfsQue.pollFirst();

                for (int d = 0; d < 8; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (!isInRange(n, nx, ny) || grid[nx][ny] != 0) continue;

                    if (nx == n - 1 && ny == n - 1) {
                        return depth;
                    }

                    grid[nx][ny] = 1;
                    bfsQue.addLast(new Point(nx, ny));
                }
            }
        }

        return -1;
    }

    boolean isInRange(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

}
