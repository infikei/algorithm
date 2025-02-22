// Solve 2025-02-21

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_28419 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long evenSum = 0;
        long oddSum = 0;

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 1; i <= n; i++) {
            int x = Integer.parseInt(st.nextToken());

            if (i % 2 == 1) {
                oddSum += x;
            } else {
                evenSum += x;
            }
        }

        if (n == 3 && oddSum > evenSum) {
            System.out.println(-1);
        } else {
            System.out.println(Math.abs(evenSum - oddSum));
        }
    }

}
