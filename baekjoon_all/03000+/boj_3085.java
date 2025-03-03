// Solve 2024-01-31
// Update 2025-03-03

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_3085 {

    static int n;
    static char[][] board;
    static int maxLen;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        board = new char[n][n];
        maxLen = 1;

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < n; y++) {
                board[x][y] = row.charAt(y);
            }
        }

        updateMaxLen();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                // 가로로 인접한 두 칸을 바꾸는 경우
                if (board[i][j - 1] != board[i][j]) {
                    swap(i, j - 1, i, j);
                    updateMaxLenGaro(i);
                    updateMaxLenSero(j - 1);
                    updateMaxLenSero(j);
                    swap(i, j - 1, i, j);
                }

                // 세로로 인접한 두 칸을 바꾸는 경우
                if (board[j - 1][i] != board[j][i]) {
                    swap(j - 1, i, j, i);
                    updateMaxLenGaro(j - 1);
                    updateMaxLenGaro(j);
                    updateMaxLenSero(i);
                    swap(j - 1, i, j, i);
                }
            }
        }

        System.out.println(maxLen);
    }

    static void swap(int x1, int y1, int x2, int y2) {
        char tmp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = tmp;
    }

    static void updateMaxLen() {
        for (int i = 0; i < n; i++) {
            int curGaroLen = 1;
            int curSeroLen = 1;

            for (int j = 1; j < n; j++) {
                // 가로로 연속한 부분의 길이를 계산
                if (board[i][j] == board[i][j - 1]) {
                    curGaroLen++;
                } else {
                    maxLen = Math.max(maxLen, curGaroLen);
                    curGaroLen = 1;
                }

                // 세로로 연속한 부분의 길이를 계산
                if (board[j][i] == board[j - 1][i]) {
                    curSeroLen++;
                } else {
                    maxLen = Math.max(maxLen, curSeroLen);
                    curSeroLen = 1;
                }
            }

            maxLen = Math.max(maxLen, Math.max(curGaroLen, curSeroLen));
        }
    }

    static void updateMaxLenGaro(int x) {
        int curGaroLen = 1;

        for (int y = 1; y < n; y++) {
            if (board[x][y - 1] == board[x][y]) {
                curGaroLen++;
            } else {
                maxLen = Math.max(maxLen, curGaroLen);
                curGaroLen = 1;
            }
        }

        maxLen = Math.max(maxLen, curGaroLen);
    }

    static void updateMaxLenSero(int y) {
        int curSeroLen = 1;

        for (int x = 1; x < n; x++) {
            if (board[x - 1][y] == board[x][y]) {
                curSeroLen++;
            } else {
                maxLen = Math.max(maxLen, curSeroLen);
                curSeroLen = 1;
            }
        }

        maxLen = Math.max(maxLen, curSeroLen);
    }

}
