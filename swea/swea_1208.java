// Solve 2024-01-30

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1208 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        for (int ti = 1; ti <= 10; ti++) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), " ");
            int[] heights = new int[100];

            for (int i = 0; i < 100; i++) {
                heights[i] = Integer.parseInt(st.nextToken());
            }

            while (n-- > 0) {
                int minVal = 101;
                int minIdx = -1;
                int maxVal = 0;
                int maxIdx = -1;

                for (int i = 0; i < 100; i++) {
                    if (heights[i] < minVal) {
                        minVal = heights[i];
                        minIdx = i;
                    }

                    if (heights[i] > maxVal) {
                        maxVal = heights[i];
                        maxIdx = i;
                    }
                }

                if (maxVal - minVal <= 1) break;

                heights[minIdx]++;
                heights[maxIdx]--;
            }

            int minVal = 101;
            int maxVal = 0;

            for (int i = 0; i < 100; i++) {
                if (heights[i] < minVal) {
                    minVal = heights[i];
                }

                if (heights[i] > maxVal) {
                    maxVal = heights[i];
                }
            }

            sb.append("#").append(ti).append(" ").append(maxVal - minVal).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
