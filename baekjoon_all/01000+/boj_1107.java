// Solve 2024-01-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1107 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        boolean[] canPress = new boolean[10];

        for (int i = 0; i < 10; i++) {
            canPress[i] = true;
        }

        if (m > 0) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < m; i++) {
                int x = Integer.parseInt(st.nextToken());
                canPress[x] = false;
            }
        }

        int ans = Math.abs(n - 100);
        int cur = n;

        loop: while (cur >= 0) {
            String curString = String.valueOf(cur);

            for (int i = 0; i < curString.length(); i++) {
                if (!canPress[curString.charAt(i) - '0']) {
                    cur--;
                    continue loop;
                }
            }

            ans = Math.min(ans, curString.length() + n - cur);
            break;
        }

        cur = n;

        loop: while (cur <= 1_000_000) {
            String curString = String.valueOf(cur);

            for (int i = 0; i < curString.length(); i++) {
                if (!canPress[curString.charAt(i) - '0']) {
                    cur++;
                    continue loop;
                }
            }

            ans = Math.min(ans, curString.length() + cur - n);
            break;
        }

        System.out.println(ans);
    }

}
