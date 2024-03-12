// Solve 2024-03-10

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_20057 {

    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { -1, 0, 1, 0 };
    static int[][] left = {
        { -2, -1, 2 },
        { -1, -2, 10 },
        { -1, -1, 7 },
        { -1, 0, 1 },
        { 0, -3, 5 },
        { 1, -2, 10 },
        { 1, -1, 7 },
        { 1, 0, 1 },
        { 2, -1, 2 }
    };
    static int[][] bottom = {
        { 0, -1, 1 },
        { 0, 1, 1 },
        { 1, -2, 2 },
        { 1, -1, 7 },
        { 1, 1, 7 },
        { 1, 2, 2 },
        { 2, -1, 10 },
        { 2, 1, 10 },
        { 3, 0, 5 }
    };
    static int n, tx, ty, td;
    static int[][] board;
    static int ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        tx = n / 2;
        ty = n / 2;
        td = 0;

        for (int i = 1; i < n; i++) {
            int iter = i;

            while (iter-- > 0) {
                move();
            }

            if (++td == 4) {
                td = 0;
            }

            iter = i;

            while (iter-- > 0) {
                move();
            }

            if (++td == 4) {
                td = 0;
            }
        }

        int iter = n - 1;

        while (iter-- > 0) {
            move();
        }

        System.out.println(ans);
        br.close();
    }

    static void move() {
        int nx = tx + dx[td];
        int ny = ty + dy[td];
        int curSand = board[nx][ny];
        int leftSand = curSand;
        board[nx][ny] = 0;

        if (td == 0) {
            for (int[] u : left) {
                int ux = tx + u[0];
                int uy = ty + u[1];
                int uSand = curSand * u[2] / 100;
                leftSand -= uSand;

                if (ux >= 0 && ux < n && uy >= 0 && uy < n) {
                    board[ux][uy] += uSand;
                } else {
                    ans += uSand;
                }
            }
        } else if (td == 1) {
            for (int[] u : bottom) {
                int ux = tx + u[0];
                int uy = ty + u[1];
                int uSand = curSand * u[2] / 100;
                leftSand -= uSand;

                if (ux >= 0 && ux < n && uy >= 0 && uy < n) {
                    board[ux][uy] += uSand;
                } else {
                    ans += uSand;
                }
            }
        } else if (td == 2) {
            for (int[] u : left) {
                int ux = tx + u[0];
                int uy = ty - u[1];
                int uSand = curSand * u[2] / 100;
                leftSand -= uSand;

                if (ux >= 0 && ux < n && uy >= 0 && uy < n) {
                    board[ux][uy] += uSand;
                } else {
                    ans += uSand;
                }
            }
        } else {
            for (int[] u : bottom) {
                int ux = tx - u[0];
                int uy = ty + u[1];
                int uSand = curSand * u[2] / 100;
                leftSand -= uSand;

                if (ux >= 0 && ux < n && uy >= 0 && uy < n) {
                    board[ux][uy] += uSand;
                } else {
                    ans += uSand;
                }
            }
        }

        int ux = nx + dx[td];
        int uy = ny + dy[td];

        if (ux >= 0 && ux < n && uy >= 0 && uy < n) {
            board[ux][uy] += leftSand;
        } else {
            ans += leftSand;
        }

        tx = nx;
        ty = ny;
    }

}
