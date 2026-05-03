// Solve 2025-05-03

import java.util.*;

class LeetCode_0200 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int numOfIslands = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (!visited[x][y] && grid[x][y] == '1') {
                    numOfIslands++;
                    bfs(grid, visited, x, y);
                }
            }
        }

        return numOfIslands;
    }

    void bfs(char[][] grid, boolean[][] visited, int x, int y) {
        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        bfsQue.addLast(new Point(x, y));
        visited[x][y] = true;

        while (!bfsQue.isEmpty()) {
            Point cur = bfsQue.pollFirst();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx >= 0 && nx < grid.length && ny >= 0 & ny < grid[0].length && !visited[nx][ny] && grid[nx][ny] == '1') {
                    visited[nx][ny] = true;
                    bfsQue.addLast(new Point(nx, ny));
                }
            }
        }
    }

}
