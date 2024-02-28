// Solve 2024-02-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1149 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int r = 0;
        int g = 0;
        int b = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int nr = Integer.parseInt(st.nextToken());
            int ng = Integer.parseInt(st.nextToken());
            int nb = Integer.parseInt(st.nextToken());

            nr += Math.min(g, b);
            ng += Math.min(r, b);
            nb += Math.min(r, g);

            r = nr;
            g = ng;
            b = nb;
        }

        System.out.println(Math.min(r, Math.min(g, b)));
        br.close();
    }

}
