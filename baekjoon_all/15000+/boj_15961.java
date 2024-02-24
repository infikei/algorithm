// Solve 2024-02-23

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15961 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int[] sushi = new int[n];
        int[] sushiCount = new int[d + 1];
        int sushiSelectedCount = 0;

        for (int i = 0; i < n; i++) {
            sushi[i] = Integer.parseInt(br.readLine());
        }

        int beginIdx = 0;
        int endIdx = 0;

        while (endIdx < k) {
            if (++sushiCount[sushi[endIdx++]] == 1) {
                sushiSelectedCount++;
            }
        }

        int maxSushiSelectedCount = sushiSelectedCount + (sushiCount[c] > 0 ? 0 : 1);

        while (beginIdx < n) {
            if (++sushiCount[sushi[endIdx]] == 1) {
                sushiSelectedCount++;
            }

            if (++endIdx == n) {
                endIdx = 0;
            }

            if (--sushiCount[sushi[beginIdx++]] == 0) {
                sushiSelectedCount--;
            }

            maxSushiSelectedCount = Math.max(maxSushiSelectedCount, sushiSelectedCount + (sushiCount[c] > 0 ? 0 : 1));
        }

        System.out.println(maxSushiSelectedCount);
        br.close();
    }

}
