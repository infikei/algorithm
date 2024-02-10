// Solve 2024-02-08

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_5215 {

    static int n, l;
    static int maxScoreSum;
    static int[] score;
    static int[] calorie;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());

            score = new int[n];
            calorie = new int[n];
            maxScoreSum = 0;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                score[i] = Integer.parseInt(st.nextToken());
                calorie[i] = Integer.parseInt(st.nextToken());
            }

            recur(0, 0, 0);

            sb.append("#").append(ti).append(" ").append(maxScoreSum).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static void recur(int beginIdx, int scoreSum, int calorieSum) {
        if (calorieSum > l) return;

        maxScoreSum = Math.max(maxScoreSum, scoreSum);

        for (int i = beginIdx; i < n; i++) {
            recur(i + 1, scoreSum + score[i], calorieSum + calorie[i]);
        }
    }

}
