// Solve 2024-02-19
// Update 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

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

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int n, m;
    static int[][] board;
    static int[][][] combs = {
        {},
        { { 0 }, { 1 }, { 2 }, { 3 } },
        { { 0, 2 }, { 1, 3 } },
        { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 } },
        { { 0, 1, 2 }, { 1, 2, 3 }, { 2, 3, 0 }, { 3, 0, 1 } },
        { { 0, 1, 2, 3 } }
    };
    static CCTV[] cctvs = new CCTV[8];
    static int cctvCount = 0;
    static int minHiddenArea;

    static void dfs(int depth, int hiddenArea) {
        if (depth == cctvCount) {
            minHiddenArea = Math.min(minHiddenArea, hiddenArea);
            return;
        }

        for (int[] comb : combs[cctvs[depth].type]) {
            for (int d : comb) {
                hiddenArea -= change(cctvs[depth].x, cctvs[depth].y, d, 0, -(depth + 1));
            }

            dfs(depth + 1, hiddenArea);

            for (int d : comb) {
                hiddenArea += change(cctvs[depth].x, cctvs[depth].y, d, -(depth + 1), 0);
            }
        }
    }

    static int change(int x, int y, int d, int value, int newValue) {
        int areaChanged = 0;
        x += dx[d];
        y += dy[d];

        while (x >= 0 && x < n && y >= 0 && y < m) {
            if (board[x][y] == 6) break;

            if (board[x][y] == value) {
                board[x][y] = newValue;
                areaChanged++;
            }

            x += dx[d];
            y += dy[d];
        }

        return areaChanged;
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
        dfs(0, hiddenArea);
        System.out.println(minHiddenArea);
        br.close();
    }

}
