// Solve 2024-04-06

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17144 {

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int r, c, px;
    static int[][] board, newBoard, tmpBoard;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        board = new int[r][c];
        newBoard = new int[r][c];
        int dustSum = 0;

        for (int x = 0; x < r; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < c; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
                dustSum += board[x][y];

            }

            if (board[x][0] == -1) {
                px = x;
                board[x][0] = 0;
                dustSum++;
            }
        }

        for (int ti = 1; ti <= t; ti++) {
            spreadDust();
            dustSum -= circulateDust();
        }

        System.out.println(dustSum);
        br.close();
    }

    static void spreadDust() {
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                newBoard[x][y] = 0;
            }
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                int remainingDust = board[x][y];
                int spreadingDust = remainingDust / 5;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && !((nx == px - 1 || nx == px) && ny == 0)) {
                        newBoard[nx][ny] += spreadingDust;
                        remainingDust -= spreadingDust;
                    }
                }

                newBoard[x][y] += remainingDust;
                board[x][y] = 0;
            }
        }

        tmpBoard = board;
        board = newBoard;
        newBoard = tmpBoard;
        tmpBoard = null;
    }

    static int circulateDust() {
        int x = px - 1, y = 0, d = 0;
        int nx = px - 2, ny = 0;

        while (nx != px - 1 || ny != 0) {
            board[x][y] = board[nx][ny];

            x = nx;
            y = ny;
            nx = x + dx[d];
            ny = y + dy[d];

            if (nx < 0 || nx >= px || ny < 0 || ny >= c) {
                if (++d == 4) d = 0;

                nx = x + dx[d];
                ny = y + dy[d];
            }
        }

        x = px;
        y = 0;
        d = 2;
        nx = px + 1;
        ny = 0;

        while (nx != px || ny != 0) {
            board[x][y] = board[nx][ny];

            x = nx;
            y = ny;
            nx = x + dx[d];
            ny = y + dy[d];

            if (nx < px || nx >= r || ny < 0 || ny >= c) {
                if (--d == -1) d = 3;

                nx = x + dx[d];
                ny = y + dy[d];
            }
        }

        int valueReturn = board[px - 1][0] + board[px][0];
        board[px - 1][0] = board[px - 1][1] = 0;
        board[px][0] = board[px][1] = 0;
        return valueReturn;
    }

}
