// Solve 2024-02-29
// Update 2025-03-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_1600_optimized {

    static int[] dx = { 0, 0, -1, 1, -2, -2, -1, -1, 1, 1, 2, 2 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -2, 2, -2, 2, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int k = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int[][] board = new int[h][w];

        for (int x = 0; x < h; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < w; y++) {
                board[x][y] = st.nextToken().charAt(0) == '0' ? 0 : 2147483647;
            }
        }

        ArrayDeque<int[]> bfsQue = new ArrayDeque<int[]>();
        board[0][0] |= 1;
        bfsQue.offer(new int[] { 0, 0, 0 });
        int minMovedCnt = -1;
        int movedCnt = 0;

        while (minMovedCnt == -1 && !bfsQue.isEmpty()) {
            int curIter = bfsQue.size();

            while (curIter-- > 0) {
                int[] pos = bfsQue.poll();
                int jumpedCnt = pos[0];
                int x = pos[1];
                int y = pos[2];

                if (x == h - 1 && y == w - 1) {
                    minMovedCnt = movedCnt;
                    break;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (jumpedCnt <= k && nx >= 0 && nx < h && ny >= 0 && ny < w && (board[nx][ny] & 1 << jumpedCnt) == 0) {
                        board[nx][ny] |= 1 << jumpedCnt;
                        bfsQue.offer(new int[] { jumpedCnt, nx, ny });
                    }
                }

                for (int d = 4; d < 12; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (jumpedCnt < k && nx >= 0 && nx < h && ny >= 0 && ny < w && (board[nx][ny] & 1 << (jumpedCnt + 1)) == 0) {
                        board[nx][ny] |= 1 << (jumpedCnt + 1);
                        bfsQue.offer(new int[] { jumpedCnt + 1, nx, ny });
                    }
                }
            }

            movedCnt++;
        }

        System.out.println(minMovedCnt);
    }

}
