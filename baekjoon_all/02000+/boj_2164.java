// Solve 2024-02-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class boj_2164 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Deque<Integer> deque = new ArrayDeque<Integer>();

        for (int i = 1; i <= n; i++) {
            deque.offerLast(i);
        }

        for (int i = 1; i < n; i++) {
            deque.pollFirst();
            deque.offerLast(deque.pollFirst());
        }

        System.out.println(deque.peekFirst());
        br.close();
    }
}
