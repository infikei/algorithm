// Solve 2025-05-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9020 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] sieve = new boolean[10001];
        sieve[1] = true;

        for (int i = 2; i < 10001; i++) {
            if (sieve[i]) continue;

            for (int j = i + i; j < 10001; j += i) {
                sieve[j] = true;
            }
        }

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());

            for (int i = n / 2; i >= 2; i--) {
                if (!sieve[i] && !sieve[n - i]) {
                    sb.append(i).append(' ').append(n - i).append('\n');
                    break;
                }
            }
        }

        System.out.print(sb);
    }

}
