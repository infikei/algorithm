// Solve 2024-02-15

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2577_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        String abc = String.valueOf(a * b * c);
        int[] digitCount = new int[10];

        for (int i = 0; i < abc.length(); i++) {
            digitCount[abc.charAt(i) - '0']++;
        }

        for (int d : digitCount) {
            sb.append(d).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
