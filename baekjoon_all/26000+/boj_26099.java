// Solve 2024-02-14
// Update 2025-07-26

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_26099 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        int[] memo = { 0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4 };
        System.out.println((n == 4 || n == 7) ? -1L : (n / 15 * 3 + memo[(int) (n % 15)]));
    }

}
