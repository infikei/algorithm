// Solve 2024-08-25

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1740 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        long p3 = 1;
        long ans = 0;

        while (n > 0) {
            if ((n & 1) == 1) {
                ans += p3;
            }

            n >>= 1;
            p3 *= 3;
        }

        System.out.println(ans);
        br.close();
    }

}
