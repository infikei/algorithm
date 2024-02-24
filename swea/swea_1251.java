// Solve 2024-02-23

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class swea_1251 {

    static class Point {
        int x, y;

        Point(int x) {
            this.x = x;
            this.y = 0;
        }

        long getDistSquare(Point p) {
            long dx = this.x - p.x;
            long dy = this.y - p.y;
            return dx * dx + dy * dy;
        }
    }

    static class Vertex implements Comparable<Vertex> {
        int idx;
        long cost;

        public Vertex(int idx, long cost) {
            this.idx = idx;
            this.cost = cost;
        }

        @Override
        public int compareTo(Vertex o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            Point[] points = new Point[n];
            st = new StringTokenizer(br.readLine(), " ");

            for (int u = 0; u < n; u++) {
                points[u] = new Point(Integer.parseInt(st.nextToken()));
            }

            st = new StringTokenizer(br.readLine(), " ");

            for (int u = 0; u < n; u++) {
                points[u].y = Integer.parseInt(st.nextToken());
            }

            double e = Double.parseDouble(br.readLine());
            PriorityQueue<Vertex> pqMinTop = new PriorityQueue<Vertex>();
            long[] minCost = new long[n];
            boolean[] visited = new boolean[n];
            long costSum = 0;
            int vertexCount = 0;

            for (int u = 0; u < n; u++) {
                minCost[u] = Long.MAX_VALUE;
            }

            minCost[0] = 0;
            pqMinTop.offer(new Vertex(0, 0));

            while (!pqMinTop.isEmpty()) {
                Vertex cur = pqMinTop.poll();

                if (visited[cur.idx]) continue;

                visited[cur.idx] = true;
                costSum += cur.cost;

                if (++vertexCount == n) break;

                for (int u = 0; u < n; u++) {
                    if (visited[u]) continue;

                    long newCost = points[cur.idx].getDistSquare(points[u]);

                    if (newCost < minCost[u]) {
                        minCost[u] = newCost;
                        pqMinTop.offer(new Vertex(u, newCost));
                    }
                }
            }

            sb.append("#").append(ti).append(" ").append(Math.round(costSum * e)).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
