// Solve 2024-02-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17070 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int[][] board = new int[n][n];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';
            }
        }

        int[][][] memo = new int[n][n][3];
        memo[0][1][0] = 1;

        for (int y = 2; y < n; y++) {
            if (board[0][y] == 0) {
                memo[0][y][0] = memo[0][y - 1][0] + memo[0][y - 1][1];
            }
        }

        for (int x = 1; x < n; x++) {
            for (int y = 1; y < n; y++) {
                if (board[x][y] == 0) {
                    memo[x][y][0] = memo[x][y - 1][0] + memo[x][y - 1][1];
                    memo[x][y][2] = memo[x - 1][y][1] + memo[x - 1][y][2];

                    if (board[x][y - 1] == 0 && board[x - 1][y] == 0) {
                        memo[x][y][1] = memo[x - 1][y - 1][0] + memo[x - 1][y - 1][1] + memo[x - 1][y - 1][2];
                    }
                }
            }
        }

        System.out.println(memo[n - 1][n - 1][0] + memo[n - 1][n - 1][1] + memo[n - 1][n - 1][2]);
        br.close();
    }

}
