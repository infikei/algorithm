// Solve 2024-05-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_4097 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) {
                break;
            }

            int maxSum = Integer.parseInt(br.readLine());
            int curSum = maxSum;

            for (int i = 1; i < n; i++) {
                int x = Integer.parseInt(br.readLine());
                curSum = (curSum < 0 ? 0 : curSum) + x;
                maxSum = curSum > maxSum ? curSum : maxSum;
            }

            sb.append(maxSum).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
