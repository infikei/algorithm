// Solve 2024-02-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17471 {

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
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] people = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            people[u] = Integer.parseInt(st.nextToken());
        }

        int[][] adj = new int[n + 1][n + 1];

        for (int u1 = 1; u1 <= n; u1++) {
            st = new StringTokenizer(br.readLine(), " ");
            int m = Integer.parseInt(st.nextToken());

            while (m-- > 0) {
                int u2 = Integer.parseInt(st.nextToken());
                adj[u1][u2] = 1;
            }
        }

        parent = new int[n + 1];
        int minDiff = Integer.MAX_VALUE;

        for (int selected = 2; selected < (1 << n); selected += 2) {
            for (int u = 1; u <= n; u++) {
                parent[u] = -1;
            }

            for (int u1 = 1; u1 <= n; u1++) {
                for (int u2 = u1 + 1; u2 <= n; u2++) {
                    if (((selected & 1 << u1) == 0) == ((selected & 1 << u2) == 0) && adj[u1][u2] == 1) {
                        unionParents(u1, u2);
                    }
                }
            }

            boolean valid = true;

            for (int u1 = 1; u1 <= n; u1++) {
                for (int u2 = u1 + 1; u2 <= n; u2++) {
                    if (((selected & 1 << u1) == 0) == ((selected & 1 << u2) == 0) && getParentOf(u1) != getParentOf(u2)) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) break;
            }

            if (valid) {
                int sumGroup0 = 0;
                int sumGroup1 = 0;

                for (int u = 1; u <= n; u++) {
                    if ((selected & 1 << u) == 0) {
                        sumGroup0 += people[u];
                    } else {
                        sumGroup1 += people[u];
                    }
                }

                minDiff = Math.min(minDiff, Math.abs(sumGroup0 - sumGroup1));
            }
        }

        System.out.println(minDiff == Integer.MAX_VALUE ? -1 : minDiff);
        br.close();
    }

}
