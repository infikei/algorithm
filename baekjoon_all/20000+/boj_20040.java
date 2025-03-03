// Solve 2025-03-02

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_20040 {

    static int[] parents;

    static int[] createParents(int n) {
        int[] parents = new int[n];

        for (int u = 0; u < n; u++) {
            parents[u] = -1;
        }

        return parents;
    }

    static int getParentOf(int u) {
        if (parents[u] < 0) return u;

        return parents[u] = getParentOf(parents[u]);
    }

    static boolean unionParents(int u1, int u2) {
        u1 = getParentOf(u1);
        u2 = getParentOf(u2);

        if (u1 == u2) return false;

        if (parents[u1] < parents[u2]) {
            parents[u1] += parents[u2];
            parents[u2] = u1;
        } else {
            parents[u2] += parents[u1];
            parents[u1] = u2;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        parents = createParents(n);

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int u1 = Integer.parseInt(st.nextToken());
            int u2 = Integer.parseInt(st.nextToken());

            if (!unionParents(u1, u2)) {
                System.out.println(i);
                return;
            }
        }

        System.out.println(0);
    }

}
