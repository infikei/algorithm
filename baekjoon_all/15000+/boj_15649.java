// Solve 2024-01-30

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15649 {

    static int n, m;
    static StringBuilder sb;
    static int[] seq;
    static boolean[] selected;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        seq = new int[m];
        selected = new boolean[n + 1];

        dfs(0);

        System.out.println(sb);
        br.close();
    }

    static void dfs(int depth) {
        if (depth == m) {
            for (int x : seq) {
                sb.append(x).append(" ");
            }

            sb.append("\n");
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!selected[i]) {
                selected[i] = true;
                seq[depth] = i;
                dfs(depth + 1);
                selected[i] = false;
            }
        }
    }

}
