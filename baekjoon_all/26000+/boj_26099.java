// Solve 2024-02-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_26099 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        int[] dp = { 0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4 };

        System.out.println(n == 4L || n == 7L ? -1L : n / 15L * 3L + dp[(int) (n % 15L)]);
        br.close();
    }

}
