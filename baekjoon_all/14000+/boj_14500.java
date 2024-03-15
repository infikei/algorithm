// Solve 2024-03-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_14500 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int maxSum = 0;
        int[][] board = new int[n][m];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        for (int x = 0; x < n; x++) {
            int curSum = board[x][0] + board[x][1] + board[x][2];

            if (x >= 1) {
                int tmpSum = curSum + board[x - 1][0];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[x - 1][1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[x - 1][2];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;
            }

            if (x + 1 < n) {
                int tmpSum = curSum + board[x + 1][0];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[x + 1][1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[x + 1][2];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;
            }

            for (int y = 3; y < m; y++) {
                curSum += board[x][y];
                maxSum = curSum > maxSum ? curSum : maxSum;
                curSum -= board[x][y - 3];

                if (x >= 1) {
                    int tmpSum = curSum + board[x - 1][y - 2];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x - 1][y - 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x - 1][y];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;
                }

                if (x + 1 < n) {
                    int tmpSum = curSum + board[x + 1][y - 2];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x + 1][y - 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x + 1][y];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;
                }
            }
        }

        for (int y = 0; y < m; y++) {
            int curSum = board[0][y] + board[1][y] + board[2][y];

            if (y >= 1) {
                int tmpSum = curSum + board[0][y - 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[1][y - 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[2][y - 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;
            }

            if (y + 1 < m) {
                int tmpSum = curSum + board[0][y + 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[1][y + 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                tmpSum = curSum + board[2][y + 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;
            }

            for (int x = 3; x < n; x++) {
                curSum += board[x][y];
                maxSum = curSum > maxSum ? curSum : maxSum;
                curSum -= board[x - 3][y];

                if (y >= 1) {
                    int tmpSum = curSum + board[x - 2][y - 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x - 1][y - 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x][y - 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;
                }

                if (y + 1 < m) {
                    int tmpSum = curSum + board[x - 2][y + 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x - 1][y + 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = curSum + board[x][y + 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;
                }
            }
        }

        for (int x = 1; x < n; x++) {
            for (int y = 1; y < m; y++) {
                int curSum = board[x - 1][y - 1] + board[x][y];
                int tmpSum = curSum + board[x - 1][y] + board[x][y - 1];
                maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                if (y + 1 < m) {
                    tmpSum = curSum + board[x - 1][y] + board[x][y + 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;
                }

                if (x + 1 < n) {
                    tmpSum = curSum + board[x][y - 1] + board[x + 1][y];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;

                    tmpSum = board[x - 1][y] + board[x][y - 1] + board[x][y] + board[x + 1][y - 1];
                    maxSum = tmpSum > maxSum ? tmpSum : maxSum;
                }
            }
        }

        System.out.println(maxSum);
        br.close();
    }

}
