// Solve 2025-10-02
// Update 2025-10-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_18214 {

    static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        int[] arr = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int maxV = 0;
        int[] last = new int[2];
        int[] cnt = new int[2];
        int[] memo = new int[n + 1];
        memo[0] = 1;

        for (int i = 1; i <= n; i++) {
            maxV = arr[i] > maxV ? arr[i] : maxV;

            if (last[0] < arr[i]) {
                last[0] = arr[i];
                cnt[0]++;
            }
            else if (last[1] < arr[i]) {
                last[1] = arr[i];
                cnt[1]++;
            }
            else {
                System.out.println(0);
                return;
            }

            if (maxV == i) {
                for (int v = maxV; v >= 0; v--) {
                    int m0 = v >= cnt[0] ? memo[v - cnt[0]] : 0;
                    int m1 = v >= cnt[1] ? memo[v - cnt[1]] : 0;
                    memo[v] = (m0 + m1) % MOD;
                }

                cnt[0] = cnt[1] = 0;
            }
        }

        long ans = 0;

        for (int i = n - m; i <= m; i++) {
            ans += memo[i];
        }

        ans %= MOD;
        System.out.println(ans);
    }

}
