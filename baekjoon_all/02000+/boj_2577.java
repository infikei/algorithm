// Solve 2024-02-15
// Update 2025-07-20

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringJoiner;

public class boj_2577 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = 1;
        int[] digitCnt = new int[10];

        for (int i = 0; i < 3; i++) {
            num *= Integer.parseInt(br.readLine());
        }

        while (num > 0) {
            digitCnt[num % 10]++;
            num /= 10;
        }

        StringJoiner sj = new StringJoiner("\n");

        for (int d : digitCnt) {
            sj.add(Integer.toString(d));
        }

        System.out.println(sj);
    }

}
