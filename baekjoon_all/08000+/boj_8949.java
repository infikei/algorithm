// Solve 2024-07-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_8949 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int[] digits = new int[7];
        int i = 0;

        while (a > 0 || b > 0) {
            digits[i] = a % 10 + b % 10;
            a /= 10;
            b /= 10;
            i++;
        }

        StringBuilder sb = new StringBuilder();

        while (--i >= 0) {
            sb.append(digits[i]);
        }

        System.out.println(sb);
        br.close();
    }

}
