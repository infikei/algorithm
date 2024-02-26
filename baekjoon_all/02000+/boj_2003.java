// Solve 2024-02-25

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2003 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        int[] numbers = new int[n + 1];

        for (int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        int beginIdx = 0;
        int endIdx = 0;
        int curSum = 0;
        int answerCount = 0;

        while (endIdx <= n) {
            if (curSum < m) {
                curSum += numbers[endIdx++];
            } else if (curSum > m) {
                curSum -= numbers[beginIdx++];
            } else {
                answerCount++;
                curSum -= numbers[beginIdx++];
            }
        }

        System.out.println(answerCount);
        br.close();
    }

}
