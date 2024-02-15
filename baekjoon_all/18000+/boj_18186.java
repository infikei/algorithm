// Solve 2024-02-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_18186 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        long b = Integer.parseInt(st.nextToken());
        long c = Integer.parseInt(st.nextToken());
        long bc = b + c;
        long bcc = bc + c;
        st = new StringTokenizer(br.readLine(), " ");
        int[] ramen = new int[n + 2];

        for (int i = 0; i < n; i++) {
            ramen[i] = Integer.parseInt(st.nextToken());
        }

        long cost = 0;

        if (b <= c) {
            for (int i = 0; i < n; i++) {
                cost += ramen[i];
            }

            cost *= b;
        } else {
            for (int i = 0; i < n; i++) {
                if (ramen[i + 1] > ramen[i + 2]) {
                    int curRamen = Math.min(ramen[i], ramen[i + 1] - ramen[i + 2]);
                    ramen[i] -= curRamen;
                    ramen[i + 1] -= curRamen;
                    cost += curRamen * bc;
                }
    
                int curRamen = Math.min(ramen[i], Math.min(ramen[i + 1], ramen[i + 2]));
                ramen[i] -= curRamen;
                ramen[i + 1] -= curRamen;
                ramen[i + 2] -= curRamen;
                cost += curRamen * bcc;
    
                cost += ramen[i] * b;
            }
        }

        System.out.println(cost);
        br.close();
    }

}
