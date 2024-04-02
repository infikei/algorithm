// Solve 2024-04-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2747 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] fibonacci = new int[46];
        fibonacci[1] = 1;

        for (int i = 2; i <= n; i++) {
            fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
        }

        System.out.println(fibonacci[n]);
        br.close();
    }

}
