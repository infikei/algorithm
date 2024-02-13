// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_10974 {

    static StringBuilder sb;
    static int n;
    static int[] seq;

    static void recur(int depth, int selected) {
        if (depth == n) {
            for (int x : seq) {
                sb.append(x).append(" ");
            }

            sb.append("\n");
            return;
        }

        for (int i = 1; i <= n; i++) {
            if ((selected & 1 << i) == 0) {
                seq[depth] = i;
                recur(depth + 1, selected | 1 << i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        seq = new int[n];
        recur(0, 0);

        System.out.print(sb);
        br.close();
    }

}
