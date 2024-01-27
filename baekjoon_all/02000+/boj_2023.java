// Solve 2024-01-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2023 {

    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dfs(0, 0);
    }

    static void dfs(int depth, int num) {
        if (depth == n) {
            System.out.println(num);
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

        for (int i = 2, ie = (int) Math.sqrt(k); i <= ie; i++) {
            if (k % i == 0) {
                return false;
            }
        }

        return true;
    }

}
