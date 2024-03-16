// Solve 2023-11-17
// Update 2024-03-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_14681 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        int y = Integer.parseInt(br.readLine());
        int quad = 0;

        if (x > 0) {
            if (y > 0) {
                quad = 1;
            } else {
                quad = 4;
            }
        } else {
            if (y > 0) {
                quad = 2;
            } else {
                quad = 3;
            }
        }

        System.out.println(quad);
        br.close();
    }

}
