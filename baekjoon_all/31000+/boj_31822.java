// Solve 2024-05-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31822 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x0 = Integer.parseInt(br.readLine().substring(0, 5));
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine().substring(0, 5));

            if (x == x0) {
                cnt++;
            }
        }

        System.out.println(cnt);
        br.close();
    }

}
