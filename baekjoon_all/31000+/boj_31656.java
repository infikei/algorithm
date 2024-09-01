// Solve 2024-08-31

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31656 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String message = br.readLine();
        StringBuilder sb = new StringBuilder();
        char lastChar = '*';

        for (int i = 0; i < message.length(); i++) {
            if (message.charAt(i) != lastChar) {
                sb.append(message.charAt(i));
                lastChar = message.charAt(i);
            }
        }

        System.out.println(sb);
        br.close();
    }

}
