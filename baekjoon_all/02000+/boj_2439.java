// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2439 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        br.close();

        StringBuilder sb = new StringBuilder();

        for (int row = 1; row <= n; row++) {
            for (int i = n - row; i > 0; i--) {
                sb.append(' ');
            }

            for (int i = 0; i < row; i++) {
                sb.append('*');
            }

            sb.append('\n');
        }

        System.out.println(sb);
    }
}
