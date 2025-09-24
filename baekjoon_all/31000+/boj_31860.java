// Solve 2025-09-23

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_31860 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n; i++) {
            pq.offer(Integer.parseInt(br.readLine()));
        }

        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        int satisfaction = 0;

        while (pq.peek() > k) {
            int curTask = pq.poll();
            satisfaction = satisfaction / 2 + curTask;
            sb.append(satisfaction).append("\n");
            cnt++;
            pq.offer(curTask - m);
        }

        System.out.println(cnt);
        System.out.print(sb.toString());
    }

}
