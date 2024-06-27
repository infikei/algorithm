// Solve 2024-06-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_23559 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        x /= 1000;

        PriorityQueue<Integer> tasteDiffs = new PriorityQueue<Integer>();
        int priceSum = 0;
        int tasteSum = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a > b) {
                priceSum += 5;
                tasteSum += a;
                tasteDiffs.offer(a - b);
            } else {
                priceSum++;
                tasteSum += b;
            }
        }

        while (priceSum > x) {
            priceSum -= 4;
            tasteSum -= tasteDiffs.poll();
        }

        System.out.println(tasteSum);
        br.close();
    }

}
