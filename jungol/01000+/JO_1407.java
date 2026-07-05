// Solve 2026-06-21

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class JO_1407 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        long[] memo = new long[] {0, 0, 1};

        {
            memo[0] = memo[1];
            memo[1] = memo[2];
            memo[2] = 0;

            int d = s.charAt(0) - '0';

            if (d >= 1) {
                memo[2] += memo[1];
            }
        }

        for (int i = 1; i < s.length(); i++) {
            int dd = s.charAt(i - 1) - '0';
            int d = s.charAt(i) - '0';
            dd = dd * 10 + d;

            memo[0] = memo[1];
            memo[1] = memo[2];
            memo[2] = 0;

            if (d >= 1) {
                memo[2] += memo[1];
            }

            if (dd >= 10 && dd <= 34) {
                memo[2] += memo[0];
            }
        }

        System.out.println(memo[2]);
    }

}
