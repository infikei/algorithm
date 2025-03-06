// Solve 2025-03-05

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_7696 {

    static long countNoRepeatNums(int len, int depth) {
        long cnt = 1;

        for (int i = depth; i <= len; i++) {
            cnt *= (i == 1 ? 9 : (11 - i));
        }

        return cnt;
    }

    static boolean isRepeatNum(int[] digits, int idxEnd) {
        for (int i = 0; i < idxEnd; i++) {
            for (int j = i + 1; j < idxEnd; j++) {
                if (digits[i] == digits[j]) {
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) break;

            int len = 0;
            long cnt = 0;

            while (len <= 9) {
                len++;
                long nxtCnt = cnt + countNoRepeatNums(len, 1);

                if (n <= nxtCnt) break;

                cnt = nxtCnt;
            }

            int[] digits = new int[len];
            digits[0] = 1;

            for (int depth = 2; depth <= len + 1; depth++) {
                while (depth >= 3 && isRepeatNum(digits, depth - 1)) {
                    digits[depth - 2]++;
                }

                while (true) {
                    long nxtCnt = cnt + countNoRepeatNums(len, depth);

                    if (n <= nxtCnt) break;

                    digits[depth - 2]++;

                    while (depth >= 3 && isRepeatNum(digits, depth - 1)) {
                        digits[depth - 2]++;
                    }

                    cnt = nxtCnt;
                }
            }

            for (int digit : digits) {
                sb.append(digit);
            }

            sb.append('\n');
        }

        System.out.print(sb);
    }

}
