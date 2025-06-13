// Solve 2024-03-02
// Update 2025-06-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_14502_bfs {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int n, m, nm;
    static int[][] board;
    static boolean[][] visited;
    static ArrayList<Point> viruses;
    static int wallCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        nm = n * m;
        board = new int[n][m];
        visited = new boolean[n][m];
        viruses = new ArrayList<>();
        wallCount = 0;

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < m; y++) {
                board[x][y] = row.charAt(y * 2) - '0';

                if (board[x][y] == 2) {
                    viruses.add(new Point(x, y));
                } else if (board[x][y] == 1) {
                    wallCount++;
                }
            }
        }

        int maxSafeArea = 0;

        for (int i = 0; i < nm; i++) {
            int ix = i / m;
            int iy = i % m;

            if (board[ix][iy] != 0) continue;

            board[ix][iy] = 1;

            for (int j = i + 1; j < nm; j++) {
                int jx = j / m;
                int jy = j % m;

                if (board[jx][jy] != 0) continue;

                board[jx][jy] = 1;

                for (int k = j + 1; k < nm; k++) {
                    int kx = k / m;
                    int ky = k % m;

                    if (board[kx][ky] != 0) continue;

                    board[kx][ky] = 1;
                    maxSafeArea = Math.max(maxSafeArea, getSafeArea());
                    board[kx][ky] = 0;
                }

                board[jx][jy] = 0;
            }

            board[ix][iy] = 0;
        }

        System.out.println(maxSafeArea);
    }

    static int getSafeArea() {
        int safeArea = nm - (wallCount + 3);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                visited[x][y] = false;
            }
        }

        for (Point virus : viruses) {
            if (visited[virus.x][virus.y]) continue;

            visited[virus.x][virus.y] = true;
            safeArea -= bfs(virus.x, virus.y);
        }

        return safeArea;
    }

    static int bfs(int x, int y) {
        int res = 1;
        visited[x][y] = true;
        ArrayDeque<Point> bfsQue = new ArrayDeque<>();
        bfsQue.addLast(new Point(x, y));

        while (!bfsQue.isEmpty()) {
            Point cur = bfsQue.pollFirst();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == 1 || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                bfsQue.addLast(new Point(nx, ny));
                res++;
            }
        }

        return res;
    }

}
