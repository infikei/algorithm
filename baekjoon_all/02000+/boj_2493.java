// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class boj_2493 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        Deque<int[]> deque = new ArrayDeque<int[]>();
        int[] ans = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            int h = Integer.parseInt(st.nextToken());

            while (!deque.isEmpty() && deque.peekLast()[0] < h) {
                deque.pollLast();
            }

            if (!deque.isEmpty()) {
                ans[i] = deque.peekLast()[1];
            }

            deque.add(new int[] { h, i });
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            sb.append(ans[i]).append(" ");
        }

        System.out.println(sb);
        br.close();
    }

}
