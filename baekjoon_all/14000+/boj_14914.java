// Solve 2024-07-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_14914 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        StringBuilder sb = new StringBuilder();

        for (int x = 1; x <= 1000; x++) {
            if (a % x == 0 && b % x == 0) {
                sb.append(x).append(' ').append(a / x).append(' ').append(b / x).append('\n');
            }
        }

        System.out.print(sb);
        br.close();
    }

}
