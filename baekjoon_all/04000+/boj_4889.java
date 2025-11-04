// Solve 2024-07-22
// Update 2025-11-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_4889 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int ti = 1;; ti++) {
            String ps = br.readLine();

            if (ps.charAt(0) == '-') break;

            int ans = 0;
            int depth = 0;

            for (int i = 0; i < ps.length(); i++) {
                if (ps.charAt(i) == '{') {
                    depth++;
                } else {
                    if (--depth == -1) {
                        depth = 1;
                        ans++;
                    }
                }
            }

            ans += depth / 2;
            sb.append(ti).append(". ").append(ans).append("\n");
        }

        System.out.print(sb);
    }

}
