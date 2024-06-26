// Solve 2024-06-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_8614 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        long ans = 0;
        int cur = 0;

        for (int i = 1; i <= n; i++) {
            int x = Integer.parseInt(st.nextToken());

            if (x >= m) {
                cur = i;
            }

            ans += cur;
        }

        System.out.println(ans);
        br.close();
    }

}
