// Solve 2024-02-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_16562 {

    static int[] parent;
    static int[] minCost;

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

                if (minCost[pu1] > minCost[pu2]) {
                    minCost[pu1] = minCost[pu2];
                }

                minCost[pu2] = 0;
            } else {
                parent[pu2] += parent[pu1];
                parent[pu1] = pu2;

                if (minCost[pu2] > minCost[pu1]) {
                    minCost[pu2] = minCost[pu1];
                }

                minCost[pu1] = 0;
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
        parent = new int[n + 1];
        minCost = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            parent[u] = -1;
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
        br.close();
    }

}
