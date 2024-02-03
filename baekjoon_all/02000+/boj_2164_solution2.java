// Solve 2024-02-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2164_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if (n == 1) {
            System.out.println(1);
        } else {
            int pow = 1;

            while (true) {
                if (n <= (pow <<= 1)) break;
            }

            // System.out.println(pow - (pow - n) * 2);
            System.out.println(n * 2 - pow);
        }

        br.close();
    }

}
