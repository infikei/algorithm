// Solve 2024-02-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1722 {

    static StringBuilder sb;
    static int n;
    static long[] fac;

    static void solution1(long k) {
        k--;
        int[] seq = new int[n];
        boolean[] selected = new boolean[n + 1];

        for (int i = 0; i < n - 1; i++) {
            long idx = k / fac[n - 1 - i];
            k %= fac[n - 1 - i];

            for (int num = 1; num <= n; num++) {
                if (selected[num]) continue;

                if (idx == 0L) {
                    selected[num] = true;
                    seq[i] = num;
                    break;
                }

                idx--;
            }
        }

        for (int num = 1; num <= n; num++) {
            if (!selected[num]) {
                seq[n - 1] = num;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            sb.append(seq[i]).append(" ");
        }
    }

    static void solution2(int[] seq) {
        long k = 1L;
        boolean[] selected = new boolean[n + 1];

        for (int i = 0; i < n; i++) {
            int idx = 0;

            for (int num = 1; num <= n; num++) {
                if (selected[num]) continue;

                if (seq[i] == num) {
                    selected[num] = true;
                    break;
                }

                idx++;
            }

            k += idx * fac[n - 1 - i];
        }

        sb.append(k);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        fac = new long[21];
        fac[0] = fac[1] = 1L;

        for (int i = 2; i <= 20; i++) {
            fac[i] = fac[i - 1] * i;
        }

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        String cmd = st.nextToken();

        if (cmd.equals("1")) {
            long k = Long.parseLong(st.nextToken());
            solution1(k);
        } else {
            int[] seq = new int[n];

            for (int i = 0; i < n; i++) {
                seq[i] = Integer.parseInt(st.nextToken());
            }

            solution2(seq);
        }

        System.out.println(sb);
        br.close();
    }

}
