// Solve 2024-01-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_30804_contest99_C_NP {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] huru = new int[n];

        for (int i = 0; i < n; i++) {
            huru[i] = Integer.parseInt(st.nextToken());
        }

        int ans = 0;

        for (int i = 1; i <= 9; i++) {
            for (int j = i + 1; j <= 9; j++) {
                int maxLen = 0;
                int curLen = 0;

                for (int k = 0; k < n; k++) {
                    if (huru[k] == i || huru[k] == j) {
                        curLen++;
                    } else {
                        maxLen = Math.max(maxLen, curLen);
                        curLen = 0;
                    }
                }

                maxLen = Math.max(maxLen, curLen);
                ans = Math.max(ans, maxLen);
            }
        }

        System.out.println(ans);
        br.close();
    }

}
