// Solve 2024-02-25

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_2230 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] numbers = new int[n];

        for (int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(numbers);
        int minDiff = 2_000_000_000;
        int beginIdx = 0;
        int endIdx = 0;

        while (endIdx < n) {
            int curDiff = numbers[endIdx] - numbers[beginIdx];

            if (curDiff < m) {
                endIdx++;
            } else if (curDiff > m) {
                minDiff = Math.min(minDiff, curDiff);
                beginIdx++;
            } else {
                minDiff = curDiff;
                break;
            }
        }

        System.out.println(minDiff);
        br.close();
    }

}
