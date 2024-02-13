// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_2573 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int n, m;
    static int[][] board;
    static int[][] newBoard;
    static int[][] tmpBoard;
    static boolean[][] visited;

    static class Point{
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    };

    static int countAreas() {
        int areaCount = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                visited[x][y] = false;
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (board[x][y] == 0 || visited[x][y]) continue;

                areaCount++;
                ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
                bfsQue.offerLast(new Point(x, y));
                visited[x][y] = true;

                while (!bfsQue.isEmpty()) {
                    Point curPos = bfsQue.pollFirst();

                    for (int d = 0; d < 4; d++) {
                        int nx = curPos.x + dx[d];
                        int ny = curPos.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0 || visited[nx][ny]) continue;

                        bfsQue.offerLast(new Point(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
        }

        return areaCount;
    }

    static void meltGlaciers() {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (board[x][y] > 0) {
                    int valueSubtract = 0;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0) {
                            valueSubtract++;
                        }
                    }

                    newBoard[x][y] = Math.max(board[x][y] - valueSubtract, 0);
                }
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                board[x][y] = 0;
            }
        }

        tmpBoard = board;
        board = newBoard;
        newBoard = tmpBoard;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n][m];
        newBoard = new int[n][m];
        visited = new boolean[n][m];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int curTime = 0;

        while (true) {
            int areaCount = countAreas();

            if (areaCount == 0) {
                curTime = 0;
                break;
            } else if (areaCount >= 2) {
                break;
            }

            curTime++;
            meltGlaciers();
        }

        System.out.println(curTime);
        br.close();
    }

}
