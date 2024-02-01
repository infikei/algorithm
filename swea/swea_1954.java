// Solve 2024-01-31

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class swea_1954 {

    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { 1, 0, -1, 0 };
    static int n, n2;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            n = Integer.parseInt(br.readLine());
            n2 = n * n;
            board = new int[n][n];
            int num = 0;
            int x = 0;
            int y = 0;
            int direction = 0;
            board[x][y] = ++num;

            while (num < n2) {
                int nx = x + dx[direction];
                int ny = y + dy[direction];

                if (!isInBoard(nx, ny) || board[nx][ny] != 0) {
                    if (++direction == 4) {
                        direction = 0;
                    }

                    nx = x + dx[direction];
                    ny = y + dy[direction];
                }

                x = nx;
                y = ny;
                board[x][y] = ++num;
            }

            sb.append("#").append(ti).append("\n");

            for (x = 0; x < n; x++) {
                for (y = 0; y < n; y++) {
                    sb.append(board[x][y]).append(" ");
                }

                sb.append("\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

    static boolean isInBoard(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

}
