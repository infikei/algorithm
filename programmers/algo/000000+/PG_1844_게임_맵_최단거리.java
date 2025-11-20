// Solve 2025-05-23

import java.util.*;

class SolutiPG_01844_게임_맵_최단거리on {

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        boolean[][] visited = new boolean[n][m];
        ArrayDeque<Point> bfsQue = new ArrayDeque<>();
        visited[0][0] = true;
        bfsQue.addLast(new Point(0, 0));
        int dist = 1;

        while (!bfsQue.isEmpty()) {
            dist++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point cur = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (!isInRange(nx, ny, n, m) || maps[nx][ny] == 0 || visited[nx][ny]) {
                        continue;
                    }
                    if (nx == n - 1 && ny == m - 1) {
                        return dist;
                    }

                    visited[nx][ny] = true;
                    bfsQue.addLast(new Point(nx, ny));
                }
            }
        }

        return -1;
    }

    boolean isInRange(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

}
