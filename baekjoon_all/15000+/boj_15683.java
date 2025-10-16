// Solve 2024-02-19
// Update 2025-10-14

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15683 {

    static class CCTV {
        int x, y, type;

        CCTV(int x, int y, int type) {
            this.x = x;
            this.y = y;
            this.type = type;
        }
    }

    static int n, m;
    static int[][] board;
    static int cctvCount = 0;
    static CCTV[] cctvs = new CCTV[8];
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int[][][] combs = {
        {},
        {{0}, {1}, {2}, {3}},
        {{0, 2}, {1, 3}},
        {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
        {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
        {{0, 1, 2, 3}}
    };
    static int minHiddenArea;

    static int change(int x, int y, int d, int val, int newVal) {
        int ret = 0;
        x += dx[d];
        y += dy[d];

        while (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != 6) {
            if (board[x][y] == val) {
                board[x][y] = newVal;
                ret++;
            }

            x += dx[d];
            y += dy[d];
        }

        return ret;
    }

    static void recur(int depth, int hiddenArea) {
        if (depth == cctvCount) {
            minHiddenArea = Math.min(minHiddenArea, hiddenArea);
            return;
        }

        CCTV curCctv = cctvs[depth];

        for (int[] dir : combs[curCctv.type]) {
            for (int d : dir) {
                hiddenArea -= change(curCctv.x, curCctv.y, d, 0, -(depth + 1));
            }

            recur(depth + 1, hiddenArea);

            for (int d : dir) {
                hiddenArea += change(curCctv.x, curCctv.y, d, -(depth + 1), 0);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n][m];
        int hiddenArea = 0;

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';

                if (board[x][y] == 0) {
                    hiddenArea++;
                } else if (board[x][y] <= 5) {
                    cctvs[cctvCount++] = new CCTV(x, y, board[x][y]);
                }
            }
        }

        minHiddenArea = hiddenArea;
        recur(0, hiddenArea);
        System.out.println(minHiddenArea);
    }

}
