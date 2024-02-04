// Solve 2024-02-04

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class boj_28066_contest45_F_NP {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Deque<Integer> deque = new ArrayDeque<Integer>();

        for (int i = 1; i <= n; i++) {
            deque.offerLast(i);
        }

        int idx = k - 1;

        while (deque.size() > 1) {
            if (++idx == k) {
                idx = 0;
                deque.offerLast(deque.pollFirst());
            } else {
                deque.pollFirst();
            }
        }

        System.out.println(deque.peekFirst());
        br.close();
    }

}
