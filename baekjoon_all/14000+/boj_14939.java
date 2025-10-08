// Solve 2024-06-23
// Update 2025-10-08

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_14939 {

    static final int INF = 1000000000;

    static int getClickCount(int[][] board, int stateBits) {
        int ret = 0;

        // 0행
        for (int y = 0; y < 10; y++) {
            if ((stateBits & (1 << y)) != 0) {
                ret++;
                board[0][y] ^= 1;
                board[1][y] ^= 1;

                if (y >= 1) {
                    board[0][y - 1] ^= 1;
                }

                if (y < 9) {
                    board[0][y + 1] ^= 1;
                }
            }
        }

        // 1~9행
        for (int x = 1; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (board[x - 1][y] == 1) {
                    ret++;
                    board[x - 1][y] = 0;
                    board[x][y] ^= 1;

                    if (y >= 1) {
                        board[x][y - 1] ^= 1;
                    }

                    if (y < 9) {
                        board[x][y + 1] ^= 1;
                    }

                    if (x < 9) {
                        board[x + 1][y] ^= 1;
                    }
                }
            }
        }

        for (int y = 0; y < 10; y++) {
            if (board[9][y] == 1) {
                return INF;
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int[10][10];
        int[][] curBoard = new int[10][10];

        for (int x = 0; x < 10; x++) {
            String line = br.readLine();

            for (int y = 0; y < 10; y++) {
                board[x][y] = line.charAt(y) == '#' ? 0 : 1;
            }
        }

        int minCnt = INF;

        for (int b = 0; b < 1024; b++) {
            // board 복사
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    curBoard[x][y] = board[x][y];
                }
            }

            int cnt = getClickCount(curBoard, b);
            minCnt = Math.min(minCnt, cnt);
        }

        System.out.println(minCnt == INF ? -1 : minCnt);
    }

}
