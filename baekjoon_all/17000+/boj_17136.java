// Solve 2024-04-07

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17136 {

    static int[][] board = new int[10][10];
    static int minCoverCnt = Integer.MAX_VALUE;
    static int[] remainingPaperCnt = { 0, 5, 5, 5, 5, 5 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int x = 0; x < 10; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < 10; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';
            }
        }

        recur(0, 0, 0);
        System.out.println(minCoverCnt == Integer.MAX_VALUE ? -1 : minCoverCnt);
        br.close();
    }

    static void recur(int x, int y, int curCoverCnt) {
        // 색종이로 덮어야 하는 칸을 찾는다.

        while (x < 10 && board[x][y] != 1) {
            if (++y == 10) {
                y = 0;
                x++;
            }
        }

        // 색종이로 덮어야 하는 칸이 더 이상 없을 경우 최솟값을 업데이트하고 탐색을 종료한다.

        if (x == 10) {
            minCoverCnt = curCoverCnt < minCoverCnt ? curCoverCnt : minCoverCnt;
            return;
        }

        // 현재 사용한 색종이의 개수가 최솟값이 될 수 없는 경우 더 이상 탐색하지 않는다.

        if (curCoverCnt > minCoverCnt) {
            return;
        }

        // 현재 위치에서 오른쪽 아래 방향로 덮을 수 있는 가장 큰 정사각형의 크기를 찾는다.

        int d = 1;

        while (d < 5) {
            if (x + d >= 10 || y + d >= 10) {
                break;
            }

            boolean flag = true;

            for (int dy = 0; dy <= d; dy++) {
                if (board[x + d][y + dy] != 1) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                break;
            }

            for (int dx = 0; dx < d; dx++) {
                if (board[x + dx][y + d] != 1) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                break;
            }

            d++;
        }

        // 덮을 수 있는 가장 큰 정사각형의 크기부터 색종이로 덮으면서 다음 탐색을 진행한다.
        // 색종이로 이미 덮은 칸은 2로 표시해서 다음 재귀에서 덮지 않는 칸으로 인식하도록 한다.

        for (int paperSize = d; paperSize >= 1; paperSize--) {
            for (int nx = x; nx < x + paperSize; nx++) {
                for (int ny = y; ny < y + paperSize; ny++) {
                    board[nx][ny] = 2;
                }
            }

            if (--remainingPaperCnt[paperSize] >= 0) {
                recur(x, y, curCoverCnt + 1);
            }

            remainingPaperCnt[paperSize]++;

            for (int nx = x; nx < x + paperSize; nx++) {
                for (int ny = y; ny < y + paperSize; ny++) {
                    board[nx][ny] = 1;
                }
            }
        }
    }

}
