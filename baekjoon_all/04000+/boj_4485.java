// Solve 2024-03-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_4485 {

    static class Point {
        int x, y, cost;

        Point(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }

    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };
    static int[][] board = new int[125][125];
    static int[][] minDist = new int[125][125];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int ti = 0;

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) {
                break;
            }

            for (int x = 0; x < n; x++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int y = 0; y < n; y++) {
                    board[x][y] = Integer.parseInt(st.nextToken());
                    minDist[x][y] = 1_000_000_000;
                }
            }

            PriorityQueue<Point> pqMinTop = new PriorityQueue<Point>(new Comparator<Point>() {

                @Override
                public int compare(Point o1, Point o2) {
                    return o1.cost < o2.cost ? -1 : o1.cost > o2.cost ? 1 : 0;
                }

            });

            minDist[0][0] = board[0][0];
            pqMinTop.offer(new Point(0, 0, board[0][0]));

            while (!pqMinTop.isEmpty()) {
                Point cur = pqMinTop.poll();

                if (cur.cost > minDist[cur.x][cur.y]) {
                    continue;
                }

                if (cur.x == n - 1 && cur.y == n - 1) {
                    break;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        continue;
                    }

                    int nDist = cur.cost + board[nx][ny];

                    if (nDist < minDist[nx][ny]) {
                        minDist[nx][ny] = nDist;
                        pqMinTop.offer(new Point(nx, ny, nDist));
                    }
                }
            }

            sb.append("Problem ").append(++ti).append(": ").append(minDist[n - 1][n - 1]).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
