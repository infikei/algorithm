// Solve 2024-02-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class boj_1927 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pqMinTop = new PriorityQueue<Integer>();

        while (n-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                sb.append(pqMinTop.isEmpty() ? 0 : pqMinTop.poll()).append("\n");
            } else {
                pqMinTop.offer(x);
            }
        }

        System.out.print(sb);
        br.close();
    }

}
