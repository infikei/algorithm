// Solve 2024-02-04
// Update 2025-11-28

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_1949 {

    static int[] people;
    static ArrayList<ArrayList<Integer>> adj;

    static int[] dfs(int cur, int par) {
        int[] res = new int[] {people[cur], 0};

        for (int nxt : adj.get(cur)) {
            if (nxt == par) continue;

            int[] nxt_res = dfs(nxt, cur);
            res[0] += nxt_res[1];
            res[1] += Math.max(nxt_res[0], nxt_res[1]);
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        people = new int[n + 1];
        adj = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int u = 1; u <= n; u++) {
            people[u] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int[] ans = dfs(1, 0);
        System.out.println(Math.max(ans[0], ans[1]));
    }

}
