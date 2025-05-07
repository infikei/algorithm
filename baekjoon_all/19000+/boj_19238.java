// Solve 2025-05-03

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_19238 {

    static class Point implements Comparable<Point> {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point o) {
            if (this.x != o.x) return this.x - o.x;

            return this.y - o.y;
        }
    }

    static class Passenger {
        Point departure;
        Point destination;

        Passenger(int x0, int y0, int x1, int y1) {
            this.departure = new Point(x0, y0);
            this.destination = new Point(x1, y1);
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int fuel = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];

        for (int x = 0; x < n; x++) {
            String line = br.readLine();

            for (int y = 0; y < n; y++) {
                board[x][y] = (line.charAt(y * 2) == '0' ? 0 : -1);
            }
        }

        st = new StringTokenizer(br.readLine(), " ");
        Point curPos = new Point(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1);
        Passenger[] passengers = new Passenger[m + 1];

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x0 = Integer.parseInt(st.nextToken()) - 1;
            int y0 = Integer.parseInt(st.nextToken()) - 1;
            int x1 = Integer.parseInt(st.nextToken()) - 1;
            int y1 = Integer.parseInt(st.nextToken()) - 1;
            passengers[i] = new Passenger(x0, y0, x1, y1);
            board[x0][y0] = i;
        }

        System.out.println(solution(n, m, fuel, board, curPos, passengers));
    }

    static int solution(int n, int m, int fuel, int[][] board, Point curPos, Passenger[] passengers) {
        int passengerCnt = 0;

        while (true) {
            int[] passengerInfo = findNearestPassenger(n, board, curPos);
            int passengerNum = passengerInfo[0];
            int distToDeparture = passengerInfo[1];

            if (passengerNum < 0) break; // 이동할 수 있는 출발지가 없는 경우

            Point departure = passengers[passengerNum].departure;
            Point destination = passengers[passengerNum].destination;
            board[departure.x][departure.y] = 0;
            int distToDestination = getMinDistOf(n, board, departure, destination);

            if (distToDestination < 0) return -1; // 현재 승객의 목적지까지 이동할 수 없는 경우

            fuel -= (distToDeparture + distToDestination);

            if (fuel < 0) return -1; // 이동 도중에 연료가 바닥나는 경우

            fuel += distToDestination * 2;
            curPos = destination;
            passengerCnt++;
        }

        return passengerCnt == m ? fuel : -1;
    }

    static int[] findNearestPassenger(int n, int[][] board, Point from) {
        if (board[from.x][from.y] > 0) {
            return new int[] { board[from.x][from.y], 0 };
        }

        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        boolean[][] visited = new boolean[n][n];
        bfsQue.addLast(new Point(from.x, from.y));
        visited[from.x][from.y] = true;
        int dist = 0;
        ArrayList<Point> departurePointList = new ArrayList<Point>();

        while (!bfsQue.isEmpty()) {
            dist++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point cur = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (!isInRange(n, nx, ny) || board[nx][ny] == -1 || visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    bfsQue.addLast(new Point(nx, ny));

                    if (board[nx][ny] > 0) {
                        departurePointList.add(new Point(nx, ny));
                        continue;
                    }
                }
            }

            if (!departurePointList.isEmpty()) {
                Point to = Collections.min(departurePointList);
                return new int[] { board[to.x][to.y], dist };
            }
        }

        return new int[] { -1, -1 };
    }

    static int getMinDistOf(int n, int[][] board, Point from, Point to) {
        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        boolean[][] visited = new boolean[n][n];
        bfsQue.addLast(new Point(from.x, from.y));
        visited[from.x][from.y] = true;
        int dist = 0;

        while (!bfsQue.isEmpty()) {
            dist++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point cur = bfsQue.pollFirst();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (!isInRange(n, nx, ny) || board[nx][ny] == -1 || visited[nx][ny]) continue;

                    if (nx == to.x && ny == to.y) return dist;

                    visited[nx][ny] = true;
                    bfsQue.addLast(new Point(nx, ny));
                }
            }
        }

        return -1;
    }

    static boolean isInRange(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

}
