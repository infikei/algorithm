// Solve 2024-01-30

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31248_contest113_C_NP {

    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        int[] dp = new int[21];
        dp[1] = 1;
        dp[2] = 3;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + 3 + (1 << (i - 2)) - 1;
        }

        sb.append(dp[n]).append('\n');
        hanoi4(n, 'A', 'D', 'B', 'C');

        System.out.print(sb);
        br.close();
    }

    static void hanoi3(int depth, char from, char to, char tmp) {
        if (depth == 1) {
            sb.append(from).append(' ').append(to).append('\n');
            return;
        }

        hanoi3(depth - 1, from, tmp, to);
        sb.append(from).append(' ').append(to).append('\n');
        hanoi3(depth - 1, tmp, to, from);
    }

    static void hanoi4(int depth, char from, char to, char tmp1, char tmp2) {
        if (depth == 1) {
            sb.append(from).append(' ').append(to).append('\n');
            return;
        }

        if (depth == 2) {
            sb.append(from).append(' ').append(tmp2).append('\n');
            sb.append(from).append(' ').append(to).append('\n');
            sb.append(tmp2).append(' ').append(to).append('\n');
            return;
        }

        hanoi3(depth - 2, from, tmp1, tmp2);
        sb.append(from).append(' ').append(tmp2).append('\n');
        sb.append(from).append(' ').append(to).append('\n');
        sb.append(tmp2).append(' ').append(to).append('\n');
        hanoi4(depth - 2, tmp1, to, from, tmp2);
    }

}
