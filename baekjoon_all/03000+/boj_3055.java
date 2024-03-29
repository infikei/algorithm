// Solve 2024-03-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_3055 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        char[][] board = new char[r][c];
        ArrayDeque<Point> waterBfsQue = new ArrayDeque<Point>();
        ArrayDeque<Point> hedgehogBfsQue = new ArrayDeque<Point>();

        for (int x = 0; x < r; x++) {
            String s = br.readLine();

            for (int y = 0; y < c; y++) {
                board[x][y] = s.charAt(y);

                if (board[x][y] == '*') {
                    waterBfsQue.offer(new Point(x, y));
                } else if (board[x][y] == 'S') {
                    hedgehogBfsQue.offer(new Point(x, y));
                }
            }
        }

        int ans = -1;
        int cur = 0;

        while (!hedgehogBfsQue.isEmpty()) {
            cur++;
            int iter = waterBfsQue.size();

            while (iter-- > 0) {
                Point curWater = waterBfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = curWater.x + dx[d];
                    int ny = curWater.y + dy[d];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && (board[nx][ny] == '.' || board[nx][ny] == 'S')) {
                        board[nx][ny] = '*';
                        waterBfsQue.offer(new Point(nx, ny));
                    }
                }
            }

            iter = hedgehogBfsQue.size();

            while (iter-- > 0) {
                Point curHedgehog = hedgehogBfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = curHedgehog.x + dx[d];
                    int ny = curHedgehog.y + dy[d];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        if (board[nx][ny] == 'D') {
                            ans = cur;
                            break;
                        }

                        if (board[nx][ny] == '.') {
                            board[nx][ny] = 'S';
                            hedgehogBfsQue.offer(new Point(nx, ny));
                        }
                    }
                }

                if (ans != -1) break;
            }

            if (ans != -1) break;
        }

        System.out.println(ans == -1 ? "KAKTUS" : ans);
        br.close();
    }

}
