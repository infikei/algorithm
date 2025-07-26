// Solve 2024-02-13
// Update 2025-07-26

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2839 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] memo = { 0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4 };
        System.out.println((n == 4 || n == 7) ? -1 : (n / 15 * 3 + memo[n % 15]));
    }

}
