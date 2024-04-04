// Solve 2024-04-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1019 {

    static long[] f(long n) {
        long[] res = new long[10];

        // 일의 자리에서 나오는 숫자의 개수 세기
        res[0] = -1;

        for (int d = 0; d < 10; d++) {
            res[d] += n / 10;

            if (d <= (n % 10)) {
                res[d]++;
            }
        }

        // 십의 자리부터 10배씩 늘려가면서 각 자리에서 나오는 숫자의 개수 세기
        long num10 = 10, num100 = 100;

        while (n >= num10) {
            res[0] -= Math.min(num10, n);

            for (int d = 0; d < 10; d++) {
                res[d] += n / num100 * num10;

                if (d < (n / num10 % 10)) {
                    res[d] += num10;
                }
            }

            res[(int) (n / num10 % 10)] += n % num10 + 1;

            num10 = num100;
            num100 *= 10;
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long n = Long.parseLong(br.readLine());
        long[] res = f(n);

        for (int d = 0; d < 10; d++) {
            sb.append(res[d]).append(" ");
        }

        System.out.println(sb);
        br.close();
    }

}
