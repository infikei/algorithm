// Solve 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class boj_2565 {

    static class Line implements Comparable<Line> {
        int a, b;

        Line(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Line o) {
            return this.a - o.a;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        List<Line> lines = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            lines.add(new Line(a, b));
        }

        Collections.sort(lines);

        int[] dp = new int[n];
        dp[0] = 1;
        int maxDp = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (lines.get(j).b < lines.get(i).b) {
                    dp[i] = Math.max(dp[i], dp[j]);
                }
            }

            dp[i]++;
            maxDp = Math.max(maxDp, dp[i]);
        }

        System.out.println(n - maxDp);
        br.close();
    }

}
