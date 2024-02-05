// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class boj_1158 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Deque<Integer> deque = new ArrayDeque<Integer>();
        int[] ans = new int[n];

        for (int i = 1; i <= n; i++) {
            deque.offerLast(i);
        }

        for (int i = 0; i < n; i++) {
            int iter = k - 1;

            while (iter-- > 0) {
                deque.offerLast(deque.pollFirst());
            }

            ans[i] = deque.pollFirst();
        }

        StringBuilder sb = new StringBuilder();
        sb.append("<").append(ans[0]);

        for (int i = 1; i < n; i++) {
            sb.append(", ").append(ans[i]);
        }

        sb.append(">\n");
        System.out.print(sb);
        br.close();
    }

}
