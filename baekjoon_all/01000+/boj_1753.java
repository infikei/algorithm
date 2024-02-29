// Solve 2024-02-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_1753 {

    static class Vertex implements Comparable<Vertex> {
        int to, dist;

        Vertex(int to, int dist) {
            this.to = to;
            this.dist = dist;
        }

        @Override
        public int compareTo(Vertex o) {
            return dist < o.dist ? -1 : dist > o.dist ? 1 : 0;
        }
    }

    static final int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(br.readLine());
        ArrayList<Vertex>[] adjList = new ArrayList[v + 1];

        for (int u = 1; u <= v; u++) {
            adjList[u] = new ArrayList<Vertex>();
        }

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            adjList[from].add(new Vertex(to, dist));
        }

        PriorityQueue<Vertex> pqMinTop = new PriorityQueue<Vertex>();
        int[] minDist = new int[v + 1];

        for (int u = 1; u <= v; u++) {
            minDist[u] = INF;
        }

        minDist[k] = 0;
        pqMinTop.offer(new Vertex(k, 0));

        while (!pqMinTop.isEmpty()) {
            Vertex curVertex = pqMinTop.poll();

            if (curVertex.dist > minDist[curVertex.to]) continue;

            for (Vertex nextVertex : adjList[curVertex.to]) {
                if (minDist[nextVertex.to] > minDist[curVertex.to] + nextVertex.dist) {
                    minDist[nextVertex.to] = minDist[curVertex.to] + nextVertex.dist;
                    pqMinTop.offer(new Vertex(nextVertex.to, minDist[nextVertex.to]));
                }
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int u = 1; u <= v; u++) {
            sb.append(minDist[u] == INF ? "INF" : minDist[u]).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
