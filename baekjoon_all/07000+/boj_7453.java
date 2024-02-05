// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_7453 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] abcd = new int[n][4];
        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            abcd[i][0] = Integer.parseInt(st.nextToken());
            abcd[i][1] = Integer.parseInt(st.nextToken());
            abcd[i][2] = Integer.parseInt(st.nextToken());
            abcd[i][3] = Integer.parseInt(st.nextToken());
        }

        int[] ab = new int[n * n];
        int[] cd = new int[n * n];
        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ab[idx] = abcd[i][0] + abcd[j][1];
                cd[idx] = abcd[i][2] + abcd[j][3];
                idx++;
            }
        }

        Arrays.sort(ab);
        Arrays.sort(cd);

        long ans = 0L;
        int i = 0;
        int j = n * n - 1;

        while (i < n * n && j >= 0) {
            int curVal = ab[i] + cd[j];

            if (curVal < 0) {
                i++;
            } else if (curVal > 0) {
                j--;
            } else {
                long abCnt = 1L;
                long cdCnt = 1L;

                while (i + 1 < n * n && ab[i] == ab[i + 1]) {
                    i++;
                    abCnt++;
                }

                while (j >= 1 && cd[j] == cd[j - 1]) {
                    j--;
                    cdCnt++;
                }

                i++;
                j--;
                ans += abCnt * cdCnt;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
