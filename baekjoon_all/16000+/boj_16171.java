// Solve 2024-07-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_16171 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String k = br.readLine();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c < '0' || c > '9') {
                sb.append(c);
            }
        }

        s = sb.toString();
        int ans = 0;

        for (int i = 0; i <= s.length() - k.length(); i++) {
            if (s.subSequence(i, i + k.length()).equals(k)) {
                ans = 1;
                break;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
