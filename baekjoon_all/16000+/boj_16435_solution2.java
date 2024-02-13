// Solve 2024-02-13

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_16435_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        PriorityQueue<Integer> pqMinTop = new PriorityQueue<Integer>(n);

        for (int i = 0; i < n; i++) {
            pqMinTop.offer(Integer.parseInt(st.nextToken()));
        }

        while (!pqMinTop.isEmpty()) {
            if (pqMinTop.poll() > l) break;

            l++;
        }

        System.out.println(l);
        br.close();
    }

}
