// Solve 2024-07-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_14925_solution2_dp {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] board = new int[m + 1][n + 1];

        for (int x = 1; x <= m; x++) {
            String line = br.readLine();

            for (int y = 1; y <= n; y++) {
                board[x][y] = line.charAt((y - 1) * 2);
            }
        }

        int maxSquareLen = 0;

        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= n; y++) {
                if (board[x][y] == '0') {
                    board[x][y] = Math.min(board[x][y - 1], Math.min(board[x - 1][y - 1], board[x - 1][y])) + 1;
                    maxSquareLen = board[x][y] > maxSquareLen ? board[x][y] : maxSquareLen;
                } else {
                    board[x][y] = 0;
                }
            }
        }

        System.out.println(maxSquareLen);
        br.close();
    }

}
