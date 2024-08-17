// Solve 2024-07-31

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_21567 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());

        long abc = (long) a * b * c;
        int[] digitCnt = new int[10];

        while (abc > 0) {
            digitCnt[(int) (abc % 10)]++;
            abc /= 10;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 10; i++) {
            sb.append(digitCnt[i]).append('\n');
        }

        System.out.print(sb);
        br.close();
    }

}
