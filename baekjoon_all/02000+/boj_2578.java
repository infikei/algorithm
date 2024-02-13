// Solve 2024-02-13

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2578 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int[][] board = new int[5][5];

        for (int x = 0; x < 5; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < 5; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int[] numbersCalled = new int[25];

        for (int x = 0; x < 5; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < 5; y++) {
                numbersCalled[x * 5 + y] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < 25; i++) {
            int num = numbersCalled[i];

            xyLoop: for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    if (board[x][y] == num) {
                        board[x][y] = 0;
                        break xyLoop;
                    }
                }
            }

            if (countBingo(board) >= 3) {
                System.out.println(i + 1);
                break;
            }
        }

        br.close();
    }

    static int countBingo(int[][] board) {
        boolean[] garoBingo = { true, true, true, true, true };
        boolean[] seroBingo = { true, true, true, true, true };
        boolean crossBingo = true;
        boolean otherCrossBingo = true;

        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (board[x][y] != 0) {
                    garoBingo[x] = false;
                    seroBingo[y] = false;
                }
            }

            if (board[x][x] != 0) {
                crossBingo = false;
            }

            if (board[x][4 - x] != 0) {
                otherCrossBingo = false;
            }
        }

        int bingoCount = 0;

        for (int i = 0; i < 5; i++) {
            if (garoBingo[i]) bingoCount++;
            if (seroBingo[i]) bingoCount++;
        }

        if (crossBingo) bingoCount++;
        if (otherCrossBingo) bingoCount++;

        return bingoCount;
    }

}
