// Solve 2024-08-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_22341 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int a = n;
        int b = n;

        for (int i = 0; i < c; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if (x < a && y < b) {
                if (a * y <= x * b) {
                    a = x;
                } else {
                    b = y;
                }
            }
        }

        System.out.println(a * b);
        br.close();
    }

}
