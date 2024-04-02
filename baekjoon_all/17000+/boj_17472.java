// Solve 2024-04-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_17472 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Vertex {
        int idx, dist;

        Vertex(int idx, int dist) {
            this.idx = idx;
            this.dist = dist;
        }
    }

    static final int INF = 1_000_000_000;
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';

                if (board[x][y] == 1) {
                    board[x][y] = -1;
                }
            }
        }

        // 1. 각 영역에 정수 값을 부여한다.

        ArrayList<Point> areaPoint = new ArrayList<Point>();
        areaPoint.add(null);
        int areaNum = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (board[x][y] == -1) {
                    areaPoint.add(new Point(x, y));
                    board[x][y] = ++areaNum;
                    ArrayDeque<Point> pointBfsQue = new ArrayDeque<Point>();
                    pointBfsQue.offer(new Point(x, y));

                    while (!pointBfsQue.isEmpty()) {
                        Point cur = pointBfsQue.poll();

                        for (int d = 0; d < 4; d++) {
                            int nx = cur.x + dx[d];
                            int ny = cur.y + dy[d];

                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == -1) {
                                board[nx][ny] = areaNum;
                                pointBfsQue.offer(new Point(nx, ny));
                            }
                        }
                    }
                }
            }
        }

        // 2. 각 영역마다 다른 영역으로 놓을 수 있는 다리 길이의 최솟값을 구하고 인접행렬로 저장한다.

        boolean[][] boardVisited = new boolean[n][m];
        int[][] adjMat = new int[areaNum + 1][areaNum + 1];

        for (int i = 1; i <= areaNum; i++) {
            for (int j = i + 1; j <= areaNum; j++) {
                adjMat[i][j] = INF;
            }
        }

        for (int u = 1; u <= areaNum; u++) {
            int ux = areaPoint.get(u).x;
            int uy = areaPoint.get(u).y;
            ArrayDeque<Point> pointBfsQue = new ArrayDeque<Point>();
            pointBfsQue.offer(new Point(ux, uy));
            boardVisited[ux][uy] = true;

            while (!pointBfsQue.isEmpty()) {
                Point curPoint = pointBfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = curPoint.x + dx[d];
                    int ny = curPoint.y + dy[d];

                    while (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0) {
                        nx += dx[d];
                        ny += dy[d];
                    }

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        int nu = board[nx][ny];

                        if (nu > u) {
                            int curBridge = Math.abs(curPoint.x - nx) + Math.abs(curPoint.y - ny) - 1;

                            if (curBridge >= 2) {
                                adjMat[u][nu] = curBridge < adjMat[u][nu] ? curBridge : adjMat[u][nu];
                            }
                        } else if (nu == u && !boardVisited[nx][ny]) {
                            boardVisited[nx][ny] = true;
                            pointBfsQue.offer(new Point(nx, ny));
                        }
                    }
                }
            }
        }

        // 3. 각 영역을 정점으로, 각 다리를 간선으로 하는 그래프에서 최소신장트리를 프림 알고리즘으로 구한다.

        PriorityQueue<Vertex> areaPqMinTop = new PriorityQueue<Vertex>(new Comparator<Vertex>() {

            @Override
            public int compare(Vertex o1, Vertex o2) {
                return o1.dist < o2.dist ? -1 : o1.dist > o2.dist ? 1 : 0;
            }

        });
        areaPqMinTop.offer(new Vertex(1, 0));
        boolean[] areaVisited = new boolean[areaNum + 1];
        int areaConnectCnt = 0;
        int bridgeDistSum = 0;

        while (!areaPqMinTop.isEmpty()) {
            Vertex curArea = areaPqMinTop.poll();

            if (areaVisited[curArea.idx]) continue;

            areaVisited[curArea.idx] = true;
            areaConnectCnt++;
            bridgeDistSum += curArea.dist;

            for (int u = 1; u <= areaNum; u++) {
                if (areaVisited[u]) continue;

                int nDist = u < curArea.idx ? adjMat[u][curArea.idx] : adjMat[curArea.idx][u];

                if (nDist < INF) {
                    areaPqMinTop.offer(new Vertex(u, nDist));
                }
            }
        }

        System.out.println(areaConnectCnt == areaNum ? bridgeDistSum : -1);
        br.close();
    }

}
