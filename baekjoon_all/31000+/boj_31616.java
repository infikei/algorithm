// Solve 2024-09-06

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31616 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        boolean sameCharacters = true;

        for (int i = 1; i < n; i++) {
            if (s.charAt(i) != s.charAt(0)) {
                sameCharacters = false;
                break;
            }
        }

        System.out.println(sameCharacters ? "Yes" : "No");
        br.close();
    }

}
