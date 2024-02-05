// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_15351 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            int score = 0;

            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);

                if (c >= 'A' && c <= 'Z') {
                    score += c - 'A' + 1;
                }
            }

            if (score == 100) {
                sb.append("PERFECT LIFE\n");
            } else {
                sb.append(score).append("\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
