// Solve 2024-07-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31561 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());

        if (m <= 30) {
            System.out.printf("%.1f%n", m * 0.5);
        } else {
            System.out.printf("%.1f%n", m * 1.5 - 30);
        }

        br.close();
    }

}
