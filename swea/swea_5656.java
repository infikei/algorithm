// Solve 2024-03-29
// Update 2024-04-07

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class swea_5656 {

    static class Bomb {
        int x, y, dist;

        Bomb(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int n, h, w;
    static int[][][] board = new int[5][15][12];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            int originNum = 0;

            for (int x = 0; x < h; x++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int y = 0; y < w; y++) {
                    board[0][x][y] = Integer.parseInt(st.nextToken());

                    if (board[0][x][y] > 0) {
                        originNum++;
                    }
                }
            }

            int maxNum = recur(0);
            sb.append("#").append(ti).append(" ").append(originNum - maxNum).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static int recur(int depth) {
        if (depth == n) {
            return 0;
        }

        int maxNum = 0;

        for (int sy = 0; sy < w; sy++) {
            int sx = 0;

            while (sx < h && board[depth][sx][sy] == 0) {
                sx++;
            }

            if (sx < h) {
                copyBoard(board[depth], board[depth + 1]);
                int curNum = bombBoard(board[depth + 1], sx, sy);
                gravityBoard(board[depth + 1]);
                curNum += recur(depth + 1);

                maxNum = curNum > maxNum ? curNum : maxNum;
            }
        }

        return maxNum;
    }

    static void copyBoard(int[][] originBoard, int[][] newBoard) {
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                newBoard[x][y] = originBoard[x][y];
            }
        }
    }

    static int bombBoard(int[][] curBoard, int sx, int sy) {
        ArrayDeque<Bomb> bombBfsQue = new ArrayDeque<Bomb>();

        if (curBoard[sx][sy] > 1) {
            bombBfsQue.offer(new Bomb(sx, sy, curBoard[sx][sy] - 1));
        }

        curBoard[sx][sy] = 0;
        int cnt = 1;

        while (!bombBfsQue.isEmpty()) {
            Bomb curBomb = bombBfsQue.poll();

            for (int d = 0; d < 4; d++) {
                int nx = curBomb.x;
                int ny = curBomb.y;

                for (int i = curBomb.dist; i > 0; i--) {
                    nx += dx[d];
                    ny += dy[d];

                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                        break;
                    }

                    if (curBoard[nx][ny] == 0) {
                        continue;
                    }

                    if (curBoard[nx][ny] > 1) {
                        bombBfsQue.offer(new Bomb(nx, ny, curBoard[nx][ny] - 1));
                    }

                    curBoard[nx][ny] = 0;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    static void gravityBoard(int[][] curBoard) {
        for (int y = 0; y < w; y++) {
            for (int x = h - 1; x >= 1; x--) {
                if (curBoard[x][y] == 0) {
                    int nx = x - 1;

                    while (nx >= 0 && curBoard[nx][y] == 0) {
                        nx--;
                    }

                    if (nx >= 0) {
                        curBoard[x][y] = curBoard[nx][y];
                        curBoard[nx][y] = 0;
                    }
                }
            }
        }
    }

}
