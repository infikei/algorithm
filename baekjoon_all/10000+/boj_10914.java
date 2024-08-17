// Solve 2024-08-09

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_10914 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        String secret = br.readLine();

        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == ' ') {
                sb.append(' ');
                sum = 0;
                cnt = 0;
                continue;
            }

            sum += secret.charAt(i) - 'a';
            cnt++;

            if (cnt == 2) {
                sb.append((char) ('a' + (sum - n + 26) % 26));
                sum = 0;
                cnt = 0;
            }
        }

        System.out.println(sb);
        br.close();
    }

}
