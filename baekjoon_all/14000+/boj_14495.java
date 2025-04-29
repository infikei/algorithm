// Solve 2025-04-29

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_14495 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        long[] similarFibonacci = createSimilarFibonacci();
        System.out.println(similarFibonacci[n]);
    }

    static long[] createSimilarFibonacci() {
        long[] similarFibonacci = new long[117];
        similarFibonacci[1] = 1;
        similarFibonacci[2] = 1;
        similarFibonacci[3] = 1;

        for (int i = 4; i <= 116; i++) {
            similarFibonacci[i] = similarFibonacci[i - 1] + similarFibonacci[i - 3];
        }

        return similarFibonacci;
    }

}
