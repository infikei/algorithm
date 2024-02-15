// Solve 2024-02-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1992 {

    static int n;
    static int[][] board;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        sb = new StringBuilder();

        for (int x = 0; x < n; x++) {
            String lineRead = br.readLine();

            for (int y = 0; y < n; y++) {
                board[x][y] = lineRead.charAt(y) - '0';
            }
        }

        recur(n, 0, 0);
        System.out.println(sb);
        br.close();
    }

    static void recur(int size, int xBegin, int yBegin) {
        boolean sameArea = true;

        xyLoop: for (int x = xBegin; x < xBegin + size; x++) {
            for (int y = yBegin; y < yBegin + size; y++) {
                if (board[x][y] != board[xBegin][yBegin]) {
                    sameArea = false;
                    break xyLoop;
                }
            }
        }

        if (sameArea) {
            sb.append(board[xBegin][yBegin]);
        } else {
            sb.append("(");
            recur(size >> 1, xBegin, yBegin);
            recur(size >> 1, xBegin, yBegin + (size >> 1));
            recur(size >> 1, xBegin + (size >> 1), yBegin);
            recur(size >> 1, xBegin + (size >> 1), yBegin + (size >> 1));
            sb.append(")");
        }
    }

}
