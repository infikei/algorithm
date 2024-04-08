// Solve 2024-04-07

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_6588 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        boolean[] primeCheck = new boolean[1_000_001];

        for (int i = 2; i <= 1_000_000; i++) {
            primeCheck[i] = true;
        }

        for (int i = 2; i <= 1_000_000; i++) {
            if (primeCheck[i]) {
                for (int j = i + i; j <= 1_000_000; j += i) {
                    primeCheck[j] = false;
                }
            }
        }

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) {
                break;
            }

            int a = 3;
            int b = n - 3;

            while (a <= b) {
                if (primeCheck[a] && primeCheck[b]) {
                    sb.append(n).append(" = ").append(a).append(" + ").append(b).append("\n");
                    break;
                }

                a += 2;
                b -= 2;
            }

            if (a > b) {
                sb.append("Goldbach's conjecture is wrong.\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
