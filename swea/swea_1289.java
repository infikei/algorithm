// Solve 2024-01-29

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class swea_1289 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            String memory = br.readLine();
            int ans = 0;
            char curChar = '0';

            for (int i = 0; i < memory.length(); i++) {
                if (memory.charAt(i) != curChar) {
                    curChar = memory.charAt(i);
                    ans++;
                }
            }

            sb.append(String.format("#%d %d%n", ti, ans));
        }

        System.out.println(sb);
        br.close();
    }

}
