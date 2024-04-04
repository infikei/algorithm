// Solve 2024-04-03

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_5604 {

    static int[] prefixSum = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55 };

    static long f(long n) {
        if (n <= 0) return 0;

        long res = 0;

        // 일의 자리에서 나오는 숫자의 합 더하기
        res += n / 10 * 45;
        res += prefixSum[(int) (n % 10)];

        // 십의 자리부터 10배씩 늘려가면서 각 자리에서 나오는 숫자의 합 더하기
        long num10 = 10, num100 = 100, num450 = 450;

        while (n >= num10) {
            res += n / num100 * num450;
            res += prefixSum[Math.max(0, (int) (n / num10 % 10 - 1))] * num10;
            res += n / num10 % 10 * (n % num10 + 1);

            num10 = num100;
            num100 *= 10;
            num450 *= 10;
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());

            long ans = f(b) - f(a - 1);
            sb.append("#").append(ti).append(" ").append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
