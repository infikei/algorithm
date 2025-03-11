// Solve 2024-01-29
// Update 2025-03-11

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_30804_contest99_C_NP {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String line = br.readLine();
        int[] fruits = new int[n];

        for (int i = 0; i < n; i++) {
            fruits[i] = line.charAt(i * 2) - '0';
        }

        int maxLen = 0;

        for (int i = 1; i <= 9; i++) {
            for (int j = i + 1; j <= 9; j++) {
                int curLen = 0;

                for (int k = 0; k < n; k++) {
                    if (fruits[k] == i || fruits[k] == j) {
                        curLen++;
                    } else {
                        maxLen = Math.max(maxLen, curLen);
                        curLen = 0;
                    }
                }

                maxLen = Math.max(maxLen, curLen);
            }
        }

        System.out.println(maxLen);
    }

}
