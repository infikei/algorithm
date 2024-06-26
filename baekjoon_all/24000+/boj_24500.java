// Solve 2024-06-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_24500 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());

        long b = 1;

        while (b <= n) {
            b <<= 1;
        }

        b--;

        long k = n ^ b;

        if (k == 0) {
            System.out.printf("1\n%d\n", n);
        } else {
            System.out.printf("2\n%d\n%d\n", k, n);
        }

        br.close();
    }

}
