// Solve 2024-02-22

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea_3124 {

    static class Edge implements Comparable<Edge> {
        int from, to, weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }

    static int[] parent = new int[100_001];

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
            st = new StringTokenizer(br.readLine(), " ");
            int v = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            Edge[] edges = new Edge[e];

            for (int u = 1; u <= v; u++) {
                parent[u] = -1;
            }

            for (int i = 0; i < e; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                edges[i] = new Edge(from, to, weight);
            }

            Arrays.sort(edges);
            long weightSum = 0;
            int edgeCount = 0;

            for (Edge edge : edges) {
                int pfrom = getParentOf(edge.from);
                int pto = getParentOf(edge.to);
                int weight = edge.weight;

                if (pfrom != pto) {
                    unionParents(pfrom, pto);
                    weightSum += weight;

                    if (++edgeCount == v - 1) {
                        break;
                    }
                }
            }

            sb.append("#").append(ti).append(" ").append(weightSum).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
