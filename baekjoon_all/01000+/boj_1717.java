// Solve 2024-02-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1717 {

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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        parent = new int[n + 1];

        for (int u = 0; u <= n; u++) {
            parent[u] = -1;
        }

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            char cmd = st.nextToken().charAt(0);
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (cmd == '0') {
                unionParents(a, b);
            } else {
                sb.append(getParentOf(a) == getParentOf(b) ? "YES\n" : "NO\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
