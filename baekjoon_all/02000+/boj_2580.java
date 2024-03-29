// Solve 2024-03-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2580 {

    static int[][] board = new int[9][9];
    static boolean[][] fixed = new boolean[9][9];
    static boolean[][] rowCheck = new boolean[9][10];
    static boolean[][] colCheck = new boolean[9][10];
    static boolean[][][] squareCheck = new boolean[3][3][10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int x = 0; x < 9; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < 9; y++) {
                int curNum = st.nextToken().charAt(0) - '0';

                if (curNum > 0) {
                    board[x][y] = curNum;
                    fixed[x][y] = true;
                    rowCheck[x][curNum] = true;
                    colCheck[y][curNum] = true;
                    squareCheck[x / 3][y / 3][curNum] = true;
                }
            }
        }

        recur(0);

        StringBuilder sb = new StringBuilder();

        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                sb.append(board[x][y]).append(" ");
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static boolean recur(int depth) {
        if (depth == 81) {
            return true;
        }

        int x = depth / 9;
        int y = depth % 9;

        if (fixed[x][y]) {
            if (recur(depth + 1)) {
                return true;
            }

            return false;
        }

        for (int curNum = 1; curNum <= 9; curNum++) {
            if (rowCheck[x][curNum] || colCheck[y][curNum] || squareCheck[x / 3][y / 3][curNum]) {
                continue;
            }

            rowCheck[x][curNum] = true;
            colCheck[y][curNum] = true;
            squareCheck[x / 3][y / 3][curNum] = true;
            board[x][y] = curNum;

            if (recur(depth + 1)) {
                return true;
            }

            rowCheck[x][curNum] = false;
            colCheck[y][curNum] = false;
            squareCheck[x / 3][y / 3][curNum] = false;
        }

        return false;
    }

}
