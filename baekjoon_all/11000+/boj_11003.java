// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class boj_11003 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        Deque<int[]> deque = new ArrayDeque<int[]>();
        st = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            int x = Integer.parseInt(st.nextToken());

            if (!deque.isEmpty() && deque.peekFirst()[1] == i - l) {
                deque.pollFirst();
            }

            while (!deque.isEmpty() && deque.peekLast()[0] >= x) {
                deque.pollLast();
            }

            deque.offerLast(new int[] { x, i });
            sb.append(deque.peekFirst()[0]).append(" ");
        }

        System.out.println(sb);
        br.close();
    }

}
