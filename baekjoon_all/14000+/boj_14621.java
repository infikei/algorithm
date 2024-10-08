// Solve 2024-08-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_14621 {

    static class Edge implements Comparable<Edge> {
        int from, to, weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static int[] parent;

    static void initParent(int n) {
        parent = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            parent[u] = -1;
        }
    }

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
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[] maleOrFemale = new boolean[n + 1];
        String line = br.readLine();

        for (int u = 1; u <= n; u++) {
            maleOrFemale[u] = line.charAt((u - 1) * 2) == 'M';
        }

        ArrayList<Edge> edges = new ArrayList<Edge>();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            if (maleOrFemale[from] != maleOrFemale[to]) {
                edges.add(new Edge(from, to, weight));
            }
        }

        Collections.sort(edges);
        initParent(n);
        int edgeCount = 0;
        int weightSum = 0;

        for (Edge edge : edges) {
            if (edgeCount == n - 1) break;

            int pFrom = getParentOf(edge.from);
            int pTo = getParentOf(edge.to);

            if (pFrom == pTo) continue;

            unionParents(pFrom, pTo);
            weightSum += edge.weight;
            edgeCount++;
        }

        System.out.println(edgeCount == n - 1 ? weightSum : -1);
        br.close();
    }

}
