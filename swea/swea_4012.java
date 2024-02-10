// Solve 2024-02-08

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_4012 {

    static int n;
    static int[][] board;
    static int minDiff;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            n = Integer.parseInt(br.readLine());
            board = new int[n][n];
            minDiff = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int j = 0; j < i; j++) {
                    board[j][i] += Integer.parseInt(st.nextToken());
                }

                for (int j = i; j < n; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            recur(0, 0, 0, 0);

            sb.append("#").append(ti).append(" ").append(minDiff).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static void recur(int depth, int selected, int beginIdx, int foodA) {
        if (depth == n / 2) {
            int foodB = 0;

            for (int i = 0; i < n; i++) {
                if ((selected & 1 << i) != 0) continue;

                for (int j = i + 1; j < n; j++) {
                    if ((selected & 1 << j) != 0) continue;

                    foodB += board[i][j];
                }
            }

            minDiff = Math.min(minDiff, Math.abs(foodA - foodB));
            return;
        }

        for (int i = beginIdx; i < n; i++) {
            int newFoodA = foodA;

            for (int j = 0; j < beginIdx; j++) {
                if ((selected & 1 << j) != 0) {
                    newFoodA += board[j][i];
                }
            }

            recur(depth + 1, selected | 1 << i, i + 1, newFoodA);
        }
    }

}
