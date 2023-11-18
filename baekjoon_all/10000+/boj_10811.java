// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj_10811 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int basket[] = new int[n + 1];

        for (int ni = 1; ni <= n; ni++) {
            basket[ni] = ni;
        }

        for (int mi = 0; mi < m; mi++) {
            st = new StringTokenizer(br.readLine(), " ");
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            while (i < j) {
                int tmp = basket[i];
                basket[i] = basket[j];
                basket[j] = tmp;

                i++;
                j--;
            }
        }

        br.close();

        for (int ni = 1; ni <= n; ni++) {
            bw.write(basket[ni] + " ");
        }

        bw.write('\n');
        bw.flush();
        bw.close();
    }
}
