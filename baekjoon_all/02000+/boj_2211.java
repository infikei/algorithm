// Solve 2024-03-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_2211 {

    static class Vertex {
        int to, dist;

        Vertex(int to, int dist) {
            this.to = to;
            this.dist = dist;
        }
    }

    static final int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<Vertex>[] adj = new ArrayList[n + 1];
        int[] minDist = new int[n + 1];
        int[] visitedFrom = new int[n + 1];
        int k = 0;

        for (int u = 1; u <= n; u++) {
            adj[u] = new ArrayList<Vertex>();
            minDist[u] = INF;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            adj[from].add(new Vertex(to, dist));
            adj[to].add(new Vertex(from, dist));
        }

        PriorityQueue<Vertex> pqMinTop = new PriorityQueue<Vertex>(new Comparator<Vertex>() {

            @Override
            public int compare(Vertex o1, Vertex o2) {
                return o1.dist < o2.dist ? -1 : o1.dist > o2.dist ? 1 : 0;
            }

        });

        pqMinTop.offer(new Vertex(1, 0));
        minDist[1] = 1;

        while (!pqMinTop.isEmpty()) {
            Vertex cur = pqMinTop.poll();

            if (cur.dist > minDist[cur.to]) continue;

            if (visitedFrom[cur.to] != 0) {
                sb.append(visitedFrom[cur.to]).append(" ").append(cur.to).append("\n");
                k++;
            }

            for (Vertex next : adj[cur.to]) {
                if (minDist[next.to] > minDist[cur.to] + next.dist) {
                    minDist[next.to] = minDist[cur.to] + next.dist;
                    visitedFrom[next.to] = cur.to;
                    pqMinTop.offer(new Vertex(next.to, minDist[next.to]));
                }
            }
        }

        System.out.println(k);
        System.out.print(sb);
        br.close();
    }

}
