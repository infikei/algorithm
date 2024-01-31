// Solve 2024-01-30

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class boj_1914 {

    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        BigInteger k = new BigInteger("2").pow(n).subtract(new BigInteger("1"));
        sb.append(k).append("\n");

        if (n <= 20) {
            hanoi(n, 1, 3, 2);
        }

        System.out.println(sb);
        br.close();
    }

    static void hanoi(int depth, int from, int to, int tmp) {
        if (depth == 0) return;

        hanoi(depth - 1, from, tmp, to);
        sb.append(from).append(" ").append(to).append("\n");
        hanoi(depth - 1, tmp, to, from);
    }

}
