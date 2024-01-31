// Solve 2024-01-30

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class swea_2805 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            String[] board = new String[n];

            for (int i = 0; i < n; i++) {
                board[i] = br.readLine();
            }

            int valueSum = 0;

            for (int i = 0; i < n; i++) {
                int startJ = Math.abs(n / 2 - i);
                int endJ = n - startJ;

                for (int j = startJ; j < endJ; j++) {
                    valueSum += board[i].charAt(j) - '0';
                }
            }

            sb.append("#").append(ti).append(" ").append(valueSum).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
