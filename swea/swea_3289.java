// Solve 2024-02-22

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_3289 {

    static int[] parent;

    static int getParentOf(int u) {
        if (parent[u] < 0) return u;
        return parent[u] = getParentOf(parent[u]);
    }

    static void unionParents(int u, int v) {
        int pu = getParentOf(u);
        int pv = getParentOf(v);

        if (pu != pv) {
            if (parent[pu] <= parent[pv]) {
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
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            parent = new int[n + 1];

            for (int u = 1; u <= n; u++) {
                parent[u] = -1;
            }

            sb.append("#").append(ti).append(" ");

            while (m-- > 0) {
                st = new StringTokenizer(br.readLine(), " ");
                String cmd = st.nextToken();
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                if (cmd.equals("0")) {
                    unionParents(a, b);
                } else {
                    sb.append(getParentOf(a) == getParentOf(b) ? 1 : 0);
                }
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
