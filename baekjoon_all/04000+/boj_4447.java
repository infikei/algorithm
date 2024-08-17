// Solve 2024-08-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_4447 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            String name = br.readLine();
            int g = 0;
            int b = 0;

            for (int j = 0; j < name.length(); j++) {
                if (name.charAt(j) == 'g' || name.charAt(j) == 'G') {
                    g++;
                } else if (name.charAt(j) == 'b' || name.charAt(j) == 'B') {
                    b++;
                }
            }

            if (g > b) {
                sb.append(name).append(" is GOOD\n");
            } else if (g < b) {
                sb.append(name).append(" is A BADDY\n");
            } else {
                sb.append(name).append(" is NEUTRAL\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
