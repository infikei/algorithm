// Solve 2024-02-20
// Update 2024-06-09

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_2636 {

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
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int cheeseCount = 0;

        for (int x = 0; x < n; x++) {
            String line = br.readLine();

            for (int y = 0; y < m; y++) {
                board[x][y] = line.charAt(y * 2) - '0';

                if (board[x][y] == 1) {
                    cheeseCount++;
                }
            }
        }

        int curTime = 0;

        while (true) {
            boolean[][] visited = new boolean[n][m];
            ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
            ArrayList<Point> cheeseNearAir = new ArrayList<Point>();
            visited[0][0] = true;
            bfsQue.offer(new Point(0, 0));

            while (!bfsQue.isEmpty()) {
                Point curPoint = bfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = curPoint.x + dx[d];
                    int ny = curPoint.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                        continue;
                    }

                    visited[nx][ny] = true;

                    if (board[nx][ny] == 1) {
                        cheeseNearAir.add(new Point(nx, ny));
                    } else {
                        bfsQue.offer(new Point(nx, ny));
                    }
                }
            }

            if (cheeseNearAir.isEmpty()) {
                break;
            }

            curTime++;
            cheeseCount = cheeseNearAir.size();

            for (Point p : cheeseNearAir) {
                board[p.x][p.y] = 0;
            }
        }

        System.out.println(curTime);
        System.out.println(cheeseCount);
        br.close();
    }

}
