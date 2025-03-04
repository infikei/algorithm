// Solve 2023-11-18
// Update 2025-03-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1546 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int scoreSum = 0;
        int scoreMax = 0;

        for (int i = 0; i < n; i++) {
            int score = Integer.parseInt(st.nextToken());
            scoreSum += score;

            if (score > scoreMax) {
                scoreMax = score;
            }
        }

        double answer = (double) (scoreSum * 100) / (n * scoreMax);

        System.out.println(String.format("%.6f", answer));
    }
}
