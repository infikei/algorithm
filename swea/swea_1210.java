// Solve 2024-01-30

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1210 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        for (int ti = 1; ti <= 10; ti++) {
            int tc = Integer.parseInt(br.readLine());
            int[][] board = new int[100][100];

            for (int i = 0; i < 100; i++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int j = 0; j < 100; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int x = 99;
            int y = 0;
            int direction = 0;

            while (board[x][y] != 2) {
                y++;
            }

            while (x != 0) {
                if (direction == 0) {
                    if (y >= 1 && board[x][y - 1] == 1) {
                        direction = -1;
                        y--;
                    } else if (y + 1 < 100 && board[x][y + 1] == 1) {
                        direction = 1;
                        y++;
                    } else {
                        x--;
                    }
                } else {
                    if (y + direction >= 0 && y + direction < 100 && board[x][y + direction] == 1) {
                        y += direction;
                    } else {
                        direction = 0;
                        x--;
                    }
                }
            }

            sb.append("#").append(tc).append(" ").append(y).append("\n");
        }

        System.out.println(sb);
        br.close();
    }

    static boolean isInBoard(int x, int y) {
        return x >= 0 && x < 100 && y >= 0 && y < 100;
    }

}
