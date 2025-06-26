// Solve 2025-06-24

import java.util.*;

class LeetCode_1514 {

    static class AdjNode implements Comparable<AdjNode> {
        int to;
        double prob;

        AdjNode(int to, double prob) {
            this.to = to;
            this.prob = prob;
        }

        public int compareTo(AdjNode rhs) {
            if (this.prob > rhs.prob) return -1;
            if (this.prob < rhs.prob) return 1;
            return 0;
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int startNode, int endNode) {
        ArrayList<ArrayList<AdjNode>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < edges.length; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double prob = succProb[i];
            adj.get(from).add(new AdjNode(to, prob));
            adj.get(to).add(new AdjNode(from, prob));
        }

        double[] maxProb = new double[n];
        maxProb[startNode] = 1.0;
        PriorityQueue<AdjNode> pq = new PriorityQueue<>();
        pq.add(new AdjNode(startNode, 1.0));

        while (!pq.isEmpty()) {
            AdjNode cur = pq.poll();

            if (cur.prob < maxProb[cur.to]) continue;

            for (AdjNode nxt : adj.get(cur.to)) {
                double nxtProb = cur.prob * nxt.prob;

                if (nxtProb > maxProb[nxt.to]) {
                    maxProb[nxt.to] = nxtProb;
                    pq.add(new AdjNode(nxt.to, nxtProb));
                }
            }
        }

        return maxProb[endNode];
    }

}
