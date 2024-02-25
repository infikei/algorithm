// Solve 2024-02-23
// Update 2024-02-24

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_1197_prim {

    static class Vertex implements Comparable<Vertex> {
        int to, weight;

        Vertex(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Vertex o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        ArrayList<Vertex>[] adj = new ArrayList[v + 1];

        for (int u = 1; u <= v; u++) {
            adj[u] = new ArrayList<Vertex>();
        }

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            adj[from].add(new Vertex(to, weight));
            adj[to].add(new Vertex(from, weight));
        }

        PriorityQueue<Vertex> pqMinTop = new PriorityQueue<Vertex>();
        int[] minWeight = new int[v + 1];
        boolean[] visited = new boolean[v + 1];
        int weightSum = 0;
        int vertexCount = 0;

        for (int u = 1; u <= v; u++) {
            minWeight[u] = Integer.MAX_VALUE;
        }

        pqMinTop.offer(new Vertex(1, 0));
        minWeight[1] = 0;

        while (!pqMinTop.isEmpty()) {
            Vertex cur = pqMinTop.poll();

            if (visited[cur.to]) continue;

            visited[cur.to] = true;
            weightSum += cur.weight;

            if (++vertexCount == v) break;

            for (Vertex next : adj[cur.to]) {
                if (visited[next.to] || next.weight >= minWeight[next.to]) continue;

                pqMinTop.offer(new Vertex(next.to, next.weight));
                minWeight[next.to] = next.weight;
            }
        }

        System.out.println(weightSum);
        br.close();
    }

}
