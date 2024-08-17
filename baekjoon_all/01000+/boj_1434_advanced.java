// Solve 2024-08-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1434_advanced {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int ans = 0;

        st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < n; i++) {
            ans += Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine(), " ");

        for (int j = 0; j < m; j++) {
            ans -= Integer.parseInt(st.nextToken());
        }

        System.out.println(ans);
        br.close();
    }

}
