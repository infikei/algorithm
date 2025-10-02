// Solve 2025-10-02

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_18214 {

    static int MOD = 1000000007;

    static void init(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = 0;
        }
    }

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
        int prevMaxV = 0;
        int[] last = new int[2];
        int[] cnt = new int[2];
        int[] memo = new int[n + 1];
        int[] nmemo = new int[n + 1];
        int[] tmp = null;
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
                init(nmemo);

                for (int v = 0; v <= prevMaxV; v++) {
                    for (int j = 0; j < 2; j++) {
                        int nv = v + cnt[j];

                        if (nv <= maxV) {
                            nmemo[nv] = (nmemo[nv] + memo[v]) % MOD;
                        }
                    }
                }

                tmp = memo;
                memo = nmemo;
                nmemo = tmp;
                tmp = null;
                cnt[0] = cnt[1] = 0;
                prevMaxV = maxV;
            }
        }

        long ans = 0;

        for (int i = n - m; i <= m; i++) {
            ans += memo[i];
        }

        System.out.println(ans % MOD);
    }

}
