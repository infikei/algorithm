// Solve 2024-06-25

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1773 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        boolean[] selected = new boolean[c + 1];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());

            for (int j = x; j <= c; j += x) {
                if (!selected[j]) {
                    selected[j] = true;
                    cnt++;
                }
            }
        }

        System.out.println(cnt);
        br.close();
    }

}
