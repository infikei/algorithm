// Solve 2024-02-23

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class swea_1251_kruskal {

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

    static class Edge implements Comparable<Edge> {
        int from, to;
        long cost;

        Edge(int from, int to, long cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    static int[] parent;

    static int getParentOf(int u) {
        if (parent[u] < 0) return u;
        return parent[u] = getParentOf(parent[u]);
    }

    static void unionParents(int u1, int u2) {
        int pu1 = getParentOf(u1);
        int pu2 = getParentOf(u2);

        if (pu1 != pu2) {
            if (parent[pu1] <= parent[pu2]) {
                parent[pu1] += parent[pu2];
                parent[pu2] = pu1;
            } else {
                parent[pu2] += parent[pu1];
                parent[pu1] = pu2;
            }
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
            ArrayList<Edge> edges = new ArrayList<Edge>();
            parent = new int[n];
            long costSum = 0;
            int edgeCount = 0;

            for (int u = 0; u < n; u++) {
                parent[u] = -1;
            }

            for (int u1 = 0; u1 < n; u1++) {
                for (int u2 = u1 + 1; u2 < n; u2++) {
                    edges.add(new Edge(u1, u2, points[u1].getDistSquare(points[u2])));
                }
            }

            Collections.sort(edges);

            for (Edge edge : edges) {
                int pFrom = getParentOf(edge.from);
                int pTo = getParentOf(edge.to);

                if (pFrom == pTo) continue;

                unionParents(pFrom, pTo);
                costSum += edge.cost;

                if (++edgeCount == n - 1) {
                    break;
                }
            }

            sb.append("#").append(ti).append(" ").append(Math.round(costSum * e)).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
