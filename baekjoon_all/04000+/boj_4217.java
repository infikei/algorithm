// Solve 2024-02-25

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_4217 {

    static int[][] hex = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 1 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 1 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 1 },
        { 0, 1, 1, 0 },
        { 0, 1, 1, 1 },
        { 1, 0, 0, 0 },
        { 1, 0, 0, 1 },
        { 1, 0, 1, 0 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 1, 1, 0, 1 },
        { 1, 1, 1, 0 },
        { 1, 1, 1, 1 }
    };
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int h, w;
    static int[][] board = new int[200][200];
    static ArrayDeque<int[]> bfsQueWhite = new ArrayDeque<int[]>();
    static ArrayDeque<int[]> bfsQueBlack = new ArrayDeque<int[]>();
    static int[] charCount = new int[6];
    static int[] resultIdx = { 1, 5, 3, 2, 4, 0 };
    static char[] resultChar = { 'A', 'D', 'J', 'K', 'S', 'W' };

    static void bfsWhiteArea(int x, int y) {
        board[x][y] = 2;
        bfsQueWhite.offer(new int[] { x, y });

        while (!bfsQueWhite.isEmpty()) {
            int[] cur = bfsQueWhite.poll();

            for (int d = 0; d < 4; d++) {
                int nx = cur[0] + dx[d];
                int ny = cur[1] + dy[d];

                if (nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] == 0) {
                    board[nx][ny] = 2;
                    bfsQueWhite.offer(new int[] { nx, ny });
                }
            }
        }
    }

    static void bfsBlackArea(int x, int y) {
        int innerWhiteCount = 0;
        board[x][y] = 3;
        bfsQueBlack.offer(new int[] { x, y });

        while (!bfsQueBlack.isEmpty()) {
            int[] cur = bfsQueBlack.poll();

            for (int d = 0; d < 4; d++) {
                int nx = cur[0] + dx[d];
                int ny = cur[1] + dy[d];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] >= 2) continue;

                if (board[nx][ny] == 0) {
                    innerWhiteCount++;
                    bfsWhiteArea(nx, ny);
                } else {
                    board[nx][ny] = 3;
                    bfsQueBlack.offer(new int[] { nx, ny });
                }
            }
        }

        charCount[innerWhiteCount]++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int ti = 0;

        while (true) {
            st = new StringTokenizer(br.readLine(), " ");
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            if (h == 0 && w == 0) break;

            for (int x = 0; x < h; x++) {
                String row = br.readLine();

                for (int y = 0; y < w; y++) {
                    char ch = row.charAt(y);
                    int val = ch >= 'a' ? ch - 'a' + 10 : ch - '0';

                    for (int dy = 0; dy < 4; dy++) {
                        board[x][y * 4 + dy] = hex[val][dy];
                    }
                }
            }

            w *= 4;

            for (int y = 0; y < w; y++) {
                if (board[0][y] == 0) {
                    bfsWhiteArea(0, y);
                }

                if (board[h - 1][y] == 0) {
                    bfsWhiteArea(h - 1, y);
                }
            }

            for (int x = 0; x < h; x++) {
                if (board[x][0] == 0) {
                    bfsWhiteArea(x, 0);
                }

                if (board[x][w - 1] == 0) {
                    bfsWhiteArea(x, w - 1);
                }
            }

            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (board[x][y] == 1) {
                        bfsBlackArea(x, y);
                    }
                }
            }

            sb.append("Case ").append(++ti).append(": ");

            for (int i = 0; i < 6; i++) {
                int curCount = charCount[resultIdx[i]];
                char curChar = resultChar[i];

                while (curCount-- > 0) {
                    sb.append(curChar);
                }

                charCount[resultIdx[i]] = 0;
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
