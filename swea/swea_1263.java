// Solve 2024-03-28

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1263 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        int[][] board = new int[1000][1000];

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    board[x][y] = st.nextToken().charAt(0) - '0';

                    if (board[x][y] == 0 && x != y) {
                        board[x][y] = 10000;
                    }
                }
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        board[i][j] = Math.min(board[i][j], board[i][k] + board[k][j]);
                    }
                }
            }

            int minValue = 10000000;

            for (int i = 0; i < n; i++) {
                int curValue = 0;

                for (int j = 0; j < n; j++) {
                    curValue += board[i][j];
                }

                if (minValue > curValue) {
                    minValue = curValue;
                }
            }

            sb.append("#").append(ti).append(" ").append(minValue).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
