// Solve 2024-05-10

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_11508 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] c = new int[n];

        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(c);

        long ans = 0;

        for (int i = n - 1; i >= 0; i -= 3) {
            ans += c[i];

            if (i - 1 >= 0) {
                ans += c[i - 1];
            }
        }

        System.out.println(ans);
        br.close();
    }

}
