// Solve 2024-01-31

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15650_bitmask {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int twoPowerN = (1 << n);

        for (int i = 0; i < twoPowerN; i++) {
            int cnt = 0;

            for (int bit = 1; bit != twoPowerN; bit <<= 1) {
                if ((i & bit) == 0) {
                    cnt++;
                }
            }

            if (cnt == m) {
                for (int j = 1, bit = (twoPowerN >> 1); bit != 0; j++, bit >>= 1) {
                    if ((i & bit) == 0) {
                        sb.append(j).append(" ");
                    }
                }

                sb.append("\n");
            }
        }

        System.out.println(sb);
        br.close();
    }

}
