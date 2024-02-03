// Solve 2024-02-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1976 {

    static int[] parent;

    static int getParent(int u) {
        if (parent[u] < 0) return u;

        return parent[u] = getParent(parent[u]);
    }

    static void unionParents(int u, int v) {
        int pu = getParent(u);
        int pv = getParent(v);

        if (pu != pv) {
            if (parent[pu] < parent[pv]) {
                parent[pu] += parent[pv];
                parent[pv] = pu;
            } else {
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        parent = new int[n + 1];

        for (int u = 1; u <= n; u++) {
            parent[u] = -1;
        }

        for (int u = 1; u <= n; u++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int v = 1; v <= n; v++) {
                String x = st.nextToken();

                if (x.equals("1")) {
                    unionParents(u, v);
                }
            }
        }

        boolean ans = true;
        st = new StringTokenizer(br.readLine(), " ");
        int u = Integer.parseInt(st.nextToken());

        for (int i = 1; i < m; i++) {
            int v = Integer.parseInt(st.nextToken());

            if (getParent(u) != getParent(v)) {
                ans = false;
                break;
            }
        }

        System.out.println(ans ? "YES" : "NO");
        br.close();
    }

}
