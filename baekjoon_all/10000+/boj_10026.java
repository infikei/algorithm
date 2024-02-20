// Solve 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class boj_10026 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];

        for (int x = 0; x < n; x++) {
            board[x] = br.readLine().toCharArray();
        }

        boolean[][] visited = new boolean[n][n];
        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        int r = 0, g = 0, b = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (visited[x][y]) continue;

                visited[x][y] = true;
                bfsQue.offer(new Point(x, y));
                char color = board[x][y];

                while (!bfsQue.isEmpty()) {
                    Point cur = bfsQue.poll();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] != color) continue;

                        visited[nx][ny] = true;
                        bfsQue.offer(new Point(nx, ny));
                    }
                }

                if (color == 'R') {
                    r++;
                } else if (color == 'G') {
                    g++;
                } else {
                    b++;
                }
            }
        }

        visited = new boolean[n][n];
        int rg = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (visited[x][y] || board[x][y] == 'B') continue;

                visited[x][y] = true;
                bfsQue.offer(new Point(x, y));

                while (!bfsQue.isEmpty()) {
                    Point cur = bfsQue.poll();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] == 'B') continue;

                        visited[nx][ny] = true;
                        bfsQue.offer(new Point(nx, ny));
                    }
                }

                rg++;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(r + g + b).append(" ").append(rg + b);
        System.out.println(sb);
        br.close();
    }

}
