// Solve 2024-01-21
// Update 2025-07-27

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9012 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String parentheses = br.readLine();
            sb.append(isParenthesesValid(parentheses) ? "YES\n" : "NO\n");
        }

        System.out.print(sb);
    }

    static boolean isParenthesesValid(String parentheses) {
        int depth = 0;

        for (int i = 0; i < parentheses.length(); i++) {
            char par = parentheses.charAt(i);

            if (par == '(') {
                depth++;
            } else {
                depth--;

                if (depth < 0) return false;
            }
        }

        return depth == 0;
    }

}
