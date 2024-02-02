// Solve 2024-02-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2961_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int[] sour = new int[n];
        int[] bitter = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            sour[i] = Integer.parseInt(st.nextToken());
            bitter[i] = Integer.parseInt(st.nextToken());
        }

        int minDiff = Math.abs(sour[0] - bitter[0]);

        for (int i = 1; i < (1 << n); i++) {
            int sourProd = 1;
            int bitterSum = 0;

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    sourProd *= sour[j];
                    bitterSum += bitter[j];
                }
            }

            int curDiff = Math.abs(sourProd - bitterSum);
            minDiff = Math.min(minDiff, curDiff);
        }

        System.out.println(minDiff);
        br.close();
    }

}
