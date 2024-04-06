// Solve 2024-04-05

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class swea_1249 {

    static class Point {
        int x, y, dist;

        Point(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            int[][] board = new int[n][n];

            for (int x = 0; x < n; x++) {
                String line = br.readLine();

                for (int y = 0; y < n; y++) {
                    board[x][y] = line.charAt(y) - '0';
                }
            }

            int[][] minDist = new int[n][n];

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    minDist[x][y] = 1_000_000;
                }
            }

            PriorityQueue<Point> pqMinTop = new PriorityQueue<Point>(new Comparator<Point>() {

                @Override
                public int compare(Point o1, Point o2) {
                    return o1.dist < o2.dist ? -1 : o1.dist > o2.dist ? 1 : 0;
                }

            });

            minDist[0][0] = 0;
            pqMinTop.offer(new Point(0, 0, 0));

            while (!pqMinTop.isEmpty()) {
                Point cur = pqMinTop.poll();
                // System.out.println(cur.x + " " + cur.y + " " + cur.dist);

                if (cur.dist > minDist[cur.x][cur.y]) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        int nDist = cur.dist + board[nx][ny];

                        if (minDist[nx][ny] > nDist) {
                            minDist[nx][ny] = nDist;
                            pqMinTop.offer(new Point(nx, ny, nDist));
                        }
                    }
                }
            }

            sb.append("#").append(ti).append(" ").append(minDist[n - 1][n - 1]).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
