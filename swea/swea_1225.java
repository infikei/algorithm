// Solve 2024-02-02

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1225 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        for (int ti = 1; ti <= 10; ti++) {
            int tc = Integer.parseInt(br.readLine());
            int[] arr = new int[8];
            st = new StringTokenizer(br.readLine(), " ");
            int k = 2147483647;

            for (int i = 0; i < 8; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                k = Math.min(k, (arr[i] - 1) / 15);
            }

            k *= 15;

            for (int i = 0; i < 8; i++) {
                arr[i] -= k;
            }

            int num = 1;
            int idx = 0;

            while (true) {
                if (arr[idx] - num <= 0) {
                    arr[idx] = 0;

                    if (++idx == 8) idx = 0;

                    break;
                }

                arr[idx] -= num;

                if (++idx == 8) idx = 0;
                if (++num == 6) num = 1;
            }

            sb.append("#").append(tc).append(" ");

            for (int i = 0; i < 8; i++) {
                sb.append(arr[idx]).append(" ");

                if (++idx == 8) idx = 0;
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
