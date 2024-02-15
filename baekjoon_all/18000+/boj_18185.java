// Solve 2024-02-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_18185 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] ramen = new int[n + 2];

        for (int i = 0; i < n; i++) {
            ramen[i] = Integer.parseInt(st.nextToken());
        }

        int cost = 0;

        for (int i = 0; i < n; i++) {
            if (ramen[i + 1] > ramen[i + 2]) {
                int curRamen = Math.min(ramen[i], ramen[i + 1] - ramen[i + 2]);
                ramen[i] -= curRamen;
                ramen[i + 1] -= curRamen;
                cost += curRamen * 5;
            }

            int curRamen = Math.min(ramen[i], Math.min(ramen[i + 1], ramen[i + 2]));
            ramen[i] -= curRamen;
            ramen[i + 1] -= curRamen;
            ramen[i + 2] -= curRamen;
            cost += curRamen * 7;

            cost += ramen[i] * 3;
        }

        System.out.println(cost);
        br.close();
    }

}
