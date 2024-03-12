// Solve 2023-11-18
// Update 2024-03-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_5597 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean students[] = new boolean[31];

        for (int i = 0; i < 28; i++) {
            int u = Integer.parseInt(br.readLine());
            students[u] = true;
        }

        for (int u = 1; u <= 30; u++) {
            if (!students[u]) {
                System.out.println(u);
            }
        }

        br.close();
    }

}
