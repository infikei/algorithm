// Solve 2024-05-24

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31821 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] prices = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            prices[i] = Integer.parseInt(br.readLine());
        }

        int m = Integer.parseInt(br.readLine());
        int amountSum = 0;

        for (int i = 0; i < m; i++) {
            int menuNum = Integer.parseInt(br.readLine());
            amountSum += prices[menuNum];
        }

        System.out.println(amountSum);
        br.close();
    }

}
