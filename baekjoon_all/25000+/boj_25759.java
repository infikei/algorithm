// Solve 2026-01-05

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_25759 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] arr = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] memo = new int[101];
        Arrays.fill(memo, -1000000000);

        for (int i = 1; i <= n; i++) {
            int mx = 0;

            for (int j = 1; j <= 100; j++) {
                mx = Math.max(mx, memo[j] + (arr[i] - j) * (arr[i] - j));
            }

            memo[arr[i]] = mx;
        }

        int ans = 0;

        for (int i = 1; i <= 100; i++) {
            ans = Math.max(ans, memo[i]);
        }

        System.out.println(ans);
    }

}
