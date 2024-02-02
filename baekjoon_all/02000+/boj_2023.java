// Solve 2024-01-26
// Update 2024-02-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2023 {

    static int n;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        dfs(0, 0);

        System.out.print(sb);
        br.close();
    }

    static void dfs(int depth, int num) {
        if (depth == n) {
            sb.append(num).append("\n");
            return;
        }

        int nextNum = num * 10;

        for (int i = 1; i <= 9; i++) {
            if (isPrime(++nextNum)) {
                dfs(depth + 1, nextNum);
            }
        }
    }

    static boolean isPrime(int k) {
        if (k == 1) return false;

        int iEnd = (int) Math.sqrt(k);

        for (int i = 2; i <= iEnd; i++) {
            if (k % i == 0) {
                return false;
            }
        }

        return true;
    }

}
