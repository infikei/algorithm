// Solve 2024-02-22
// Update 2025-03-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_16562 {

    static int[] parents;
    static int[] minCost;

    static int getParentOf(int u) {
        if (parents[u] < 0) return u;

        return parents[u] = getParentOf(parents[u]);
    }

    static void unionParents(int u1, int u2) {
        u1 = getParentOf(u1);
        u2 = getParentOf(u2);

        if (u1 != u2) {
            if (parents[u1] <= parents[u2]) {
                parents[u1] += parents[u2];
                parents[u2] = u1;

                if (minCost[u1] > minCost[u2]) {
                    minCost[u1] = minCost[u2];
                }

                minCost[u2] = 0;
            } else {
                parents[u2] += parents[u1];
                parents[u1] = u2;

                if (minCost[u2] > minCost[u1]) {
                    minCost[u2] = minCost[u1];
                }

                minCost[u1] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        parents = new int[n + 1];
        minCost = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            parents[u] = -1;
            minCost[u] = Integer.parseInt(st.nextToken());
        }

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int u1 = Integer.parseInt(st.nextToken());
            int u2 = Integer.parseInt(st.nextToken());
            unionParents(u1, u2);
        }

        int minSumCost = 0;

        for (int u = 1; u <= n; u++) {
            minSumCost += minCost[u];

            if (minSumCost > k) break;
        }

        System.out.println(minSumCost > k ? "Oh no" : minSumCost);
    }

}
