// Solve 2024-02-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_3109 {

    static int r, c;
    static boolean[][] board;
    static int pipelineCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        board = new boolean[r][c];

        for (int x = 0; x < r; x++) {
            String row = br.readLine();

            for (int y = 0; y < c; y++) {
                board[x][y] = row.charAt(y) == '.';
            }
        }

        for (int x = 0; x < r; x++) {
            dfs(x, 1);
        }

        System.out.println(pipelineCount);
        br.close();
    }

    static boolean dfs(int x, int y) {
        if (y == c) {
            pipelineCount++;
            return true;
        }

        if (x >= 1 && board[x - 1][y]) {
            board[x - 1][y] = false;
            if (dfs(x - 1, y + 1)) return true;
        }

        if (board[x][y]) {
            board[x][y] = false;
            if (dfs(x, y + 1)) return true;
        }

        if (x + 1 < r && board[x + 1][y]) {
            board[x + 1][y] = false;
            if (dfs(x + 1, y + 1)) return true;
        }

        return false;
    }

}
