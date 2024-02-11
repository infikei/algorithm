// Solve 2024-01-31
// Update 2024-02-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15650_bitmask {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int selected = 0; selected < (1 << n); selected++) {
            int cnt = 0;

            for (int bit = 1 << (n - 1); bit != 0; bit >>= 1) {
                if ((selected & bit) == 0) {
                    cnt++;
                }
            }

            if (cnt == m) {
                int i = 0;

                for (int bit = 1 << (n - 1); bit != 0; bit >>= 1) {
                    i++;

                    if ((selected & bit) == 0) {
                        sb.append(i).append(" ");
                    }
                }

                sb.append("\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
