// Solve 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_10798 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] strings = new String[5];

        for (int i = 0; i < 5; i++) {
            strings[i] = br.readLine();
        }

        for (int j = 0; j < 15; j++) {
            for (int i = 0; i < 5; i++) {
                if (j < strings[i].length()) {
                    sb.append(strings[i].charAt(j));
                }
            }
        }

        System.out.println(sb);
        br.close();
    }

}
