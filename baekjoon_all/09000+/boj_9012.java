// Solve 2024-01-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9012 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int testCase = Integer.parseInt(br.readLine());

        while (testCase-- > 0) {
            String ps = br.readLine();
            int psDepth = 0;
            boolean isVps = true;

            for (int i = 0; i < ps.length(); i++) {
                char ch = ps.charAt(i);

                if (ch == '(') {
                    psDepth++;
                } else {
                    psDepth--;
                }

                if (psDepth < 0) {
                    isVps = false;
                    break;
                }
            }

            if (psDepth != 0) {
                isVps = false;
            }

            sb.append(isVps ? "YES\n" : "NO\n");
        }

        System.out.println(sb);
        br.close();
    }
}
