// Solve 2024-02-04

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_1949 {

    static int[] people;
    static List<List<Integer>> adj;
    static boolean[] visited;
    static int[][] dp;

    static void dfs(int nowNode) {
        visited[nowNode] = true;
        dp[nowNode][0] = 0;
        dp[nowNode][1] = people[nowNode];

        for (int nextNode : adj.get(nowNode)) {
            if (visited[nextNode]) continue;

            dfs(nextNode);
            dp[nowNode][0] += Math.max(dp[nextNode][0], dp[nextNode][1]);
            dp[nowNode][1] += dp[nextNode][0];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        people = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            people[i] = Integer.parseInt(st.nextToken());
        }

        adj = new ArrayList<List<Integer>>();

        for (int u = 0; u <= n; u++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        visited = new boolean[n + 1];
        dp = new int[n + 1][2];
        dfs(1);

        System.out.println(Math.max(dp[1][0], dp[1][1]));
        br.close();
    }

}
