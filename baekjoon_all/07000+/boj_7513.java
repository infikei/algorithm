// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_7513 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int m = Integer.parseInt(br.readLine());
            String[] words = new String[m];

            for (int i = 0; i < m; i++) {
                words[i] = br.readLine();
            }

            if (ti >= 2) sb.append("\n");

            sb.append("Scenario #").append(ti).append(":\n");

            int n = Integer.parseInt(br.readLine());

            while (n-- > 0) {
                st = new StringTokenizer(br.readLine(), " ");
                int k = Integer.parseInt(st.nextToken());

                while (k-- > 0) {
                    int idx = Integer.parseInt(st.nextToken());
                    sb.append(words[idx]);
                }

                sb.append("\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
