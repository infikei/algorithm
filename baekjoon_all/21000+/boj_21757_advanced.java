// Solve 2024-07-23

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_21757_advanced {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] prefixSum = new int[n];
        prefixSum[0] = Integer.parseInt(st.nextToken());

        for (int i = 1; i < n; i++) {
            prefixSum[i] = Integer.parseInt(st.nextToken()) + prefixSum[i - 1];
        }

        long ans = 0;

        if (prefixSum[n - 1] % 4 == 0) {
            int partSum = prefixSum[n - 1] / 4;
            long[] cntDp = new long[4];
            cntDp[0] = 1;

            for (int i = 0; i < n - 1; i++) {
                if (prefixSum[i] == partSum * 3) {
                    cntDp[3] += cntDp[2];
                }

                if (prefixSum[i] == partSum * 2) {
                    cntDp[2] += cntDp[1];
                }

                if (prefixSum[i] == partSum) {
                    cntDp[1] += cntDp[0];
                }
            }

            ans = cntDp[3];
        }

        System.out.println(ans);
        br.close();
    }

}
