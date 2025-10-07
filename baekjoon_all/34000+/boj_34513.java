// Solve 2025-10-07

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class boj_34513 {

    static class Point {
        int x, y, d;

        Point(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }

    static final int INF = 1000000000;
    static int[] dx = new int[] {0, 1, 0, -1};
    static int[] dy = new int[] {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] board = new String[n];
        Point blackRook = new Point(0, 0, 0);
        Point whiteKing = new Point(0, 0, 0);

        for (int x = 0; x < n; x++) {
            board[x] = br.readLine();

            for (int y = 0; y < n; y++) {
                if (board[x].charAt(y) == 'R') {
                    blackRook = new Point(x, y, 0);
                } else if (board[x].charAt(y) == 'K') {
                    whiteKing = new Point(x, y, 0);
                }
            }
        }

        ArrayDeque<Point> bfsQue = new ArrayDeque<>();
        int[][][] dist = new int[n][n][2];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                dist[x][y][0] = INF;
                dist[x][y][1] = INF;
            }
        }

        bfsQue.addLast(new Point(blackRook.x, blackRook.y, 0));
        bfsQue.addLast(new Point(blackRook.x, blackRook.y, 1));
        dist[blackRook.x][blackRook.y][0] = 1;
        dist[blackRook.x][blackRook.y][1] = 1;

        while (!bfsQue.isEmpty()) {
            Point cur = bfsQue.pollFirst();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                int nd = d % 2;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx].charAt(ny) == 'B') continue;

                if (board[cur.x].charAt(cur.y) == 'W' || nd != cur.d) {
                    int ndist = dist[cur.x][cur.y][cur.d] + 1;

                    if (ndist < dist[nx][ny][nd]) {
                        dist[nx][ny][nd] = ndist;
                        bfsQue.addLast(new Point(nx, ny, nd));
                    }
                } else {
                    int ndist = dist[cur.x][cur.y][cur.d];

                    if (ndist < dist[nx][ny][nd]) {
                        dist[nx][ny][nd] = ndist;
                        bfsQue.addFirst(new Point(nx, ny, nd));
                    }
                }
            }
        }

        int ans = Math.min(dist[whiteKing.x][whiteKing.y][0], dist[whiteKing.x][whiteKing.y][1]);
        System.out.println(ans == INF ? -1 : ans);
    }

}
