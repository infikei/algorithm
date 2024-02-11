// Solve 2024-01-30
// Update 2024-02-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15649 {

    static StringBuilder sb;
    static int n, m;
    static int[] seq;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        seq = new int[m];
        dfs(0, 0);

        System.out.print(sb);
        br.close();
    }

    static void dfs(int depth, int selected) {
        if (depth == m) {
            for (int x : seq) {
                sb.append(x).append(" ");
            }

            sb.append("\n");
            return;
        }

        for (int i = 1; i <= n; i++) {
            if ((selected & 1 << i) == 0) {
                seq[depth] = i;
                dfs(depth + 1, selected | 1 << i);
            }
        }
    }

}
