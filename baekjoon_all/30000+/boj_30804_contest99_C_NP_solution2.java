// Solve 2024-01-29
// Update 2024-07-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_30804_contest99_C_NP_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String line = br.readLine();
        int[] fruits = new int[n];

        for (int i = 0; i < n; i++) {
            fruits[i] = line.charAt(i * 2) - '0';
        }

        int left = 0;
        int right = 0;
        int[] cnt = new int[10];
        int kindOfFruits = 0;
        int maxLen = 0;

        while (right < n) {
            cnt[fruits[right]]++;

            if (cnt[fruits[right]] == 1) {
                kindOfFruits++;

                while (kindOfFruits == 3) {
                    cnt[fruits[left]]--;

                    if (cnt[fruits[left]] == 0) {
                        kindOfFruits--;
                    }

                    left++;
                }
            }

            right++;
            int curLen = right - left;
            maxLen = curLen > maxLen ? curLen : maxLen;
        }

        System.out.println(maxLen);
        br.close();
    }

}
