// Solve 2024-08-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_15813 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String name = br.readLine();
        int nameScore = 0;

        for (int i = 0; i < n; i++) {
            nameScore += name.charAt(i) - 'A' + 1;
        }

        System.out.println(nameScore);
        br.close();
    }

}
