// Solve 2024-02-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_13023 {

    static ArrayList<Integer>[] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n];

        for (int u = 0; u < n; u++) {
            adj[u] = new ArrayList<Integer>();
        }

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            adj[from].add(to);
            adj[to].add(from);
        }

        int[] selected = new int[5];
        boolean foundFlag = false;

        for (int u = 0; u < n; u++) {
            if (dfs(0, u, selected)) {
                foundFlag = true;
                break;
            }
        }

        System.out.println(foundFlag ? 1 : 0);
        br.close();
    }

    static boolean dfs(int depth, int curNode, int[] selected) {
        for (int i = 0; i < depth; i++) {
            if (selected[i] == curNode) {
                return false;
            }
        }

        if (depth == 4) {
            return true;
        }

        selected[depth] = curNode;

        for (int nextNode : adj[curNode]) {
            if (dfs(depth + 1, nextNode, selected)) {
                return true;
            }
        }

        return false;
    }

}
