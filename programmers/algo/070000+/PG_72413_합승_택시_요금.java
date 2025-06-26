// Solve 2025-06-25

import java.util.*;

class PG_72413_합승_택시_요금 {

    static class AdjNode implements Comparable<AdjNode> {
        int to;
        int cost;

        AdjNode(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(AdjNode o) {
            return this.cost - o.cost;
        }
    }

    int[] dijkstra(int startNode, int n, List<List<AdjNode>> adj) {
        int[] minCost = new int[n + 1];
        Arrays.fill(minCost, 100000000);
        minCost[startNode] = 0;

        PriorityQueue<AdjNode> pq = new PriorityQueue<>();
        pq.add(new AdjNode(startNode, 0));

        while (!pq.isEmpty()) {
            AdjNode cur = pq.poll();

            if (cur.cost > minCost[cur.to]) continue;

            for (AdjNode nxt : adj.get(cur.to)) {
                int costToNxt = cur.cost + nxt.cost;

                if (costToNxt < minCost[nxt.to]) {
                    minCost[nxt.to] = costToNxt;
                    pq.add(new AdjNode(nxt.to, costToNxt));
                }
            }
        }

        return minCost;
    }

    public int solution(int n, int s, int a, int b, int[][] fares) {
        List<List<AdjNode>> adj = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < fares.length; i++) {
            int from = fares[i][0];
            int to = fares[i][1];
            int cost = fares[i][2];  
            adj.get(from).add(new AdjNode(to, cost));
            adj.get(to).add(new AdjNode(from, cost));
        }

        int[] costToS = dijkstra(s, n, adj);
        int[] costToA = dijkstra(a, n, adj);
        int[] costToB = dijkstra(b, n, adj);
        int answer = 1000000000;

        for (int i = 1; i <= n; i++) {
            answer = Math.min(answer, costToS[i] + costToA[i] + costToB[i]);
        }

        return answer;
    }

}
