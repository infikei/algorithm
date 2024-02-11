// Solve 2024-02-10
// Update 2024-02-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class boj_11279 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pqMaxTop = new PriorityQueue<Integer>(Collections.reverseOrder());

        while (n-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                sb.append(pqMaxTop.isEmpty() ? 0 : pqMaxTop.poll()).append("\n");
            } else {
                pqMaxTop.offer(x);
            }
        }

        System.out.print(sb);
        br.close();
    }

}
