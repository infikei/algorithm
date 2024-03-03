// Solve 2024-03-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_14502 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int n, m, nm;
    static int[][] board;
    static boolean[][] visited;
    static ArrayList<int[]> viruses;
    static int wallCount;
    static int maxSafeCount, curSafeCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        nm = n * m;
        board = new int[n][m];
        visited = new boolean[n][m];
        viruses = new ArrayList<int[]>();
        wallCount = 0;

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';

                if (board[x][y] == 2) {
                    viruses.add(new int[] { x, y });
                } else if (board[x][y] == 1) {
                    wallCount++;
                }
            }
        }

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
                    updateMaxSafeCount();
                    board[kx][ky] = 0;
                }

                board[jx][jy] = 0;
            }

            board[ix][iy] = 0;
        }

        System.out.println(maxSafeCount);
        br.close();
    }

    static void updateMaxSafeCount() {
        curSafeCount = nm - (wallCount + 3);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                visited[x][y] = false;
            }
        }

        for (int[] virus : viruses) {
            if (!visited[virus[0]][virus[1]]) {
                visited[virus[0]][virus[1]] = true;
                curSafeCount--;
                dfs(virus[0], virus[1]);
            }
        }

        maxSafeCount = Math.max(maxSafeCount, curSafeCount);
    }

    static void dfs(int x, int y) {
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                curSafeCount--;
                dfs(nx, ny);
            }
        }
    }

}
