// Solve 2024-07-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2145 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) {
                break;
            }

            while (n >= 10) {
                int k = 0;

                while (n > 0) {
                    k += n % 10;
                    n /= 10;
                }

                n = k;
            }

            sb.append(n).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
