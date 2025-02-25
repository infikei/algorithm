// Solve 2025-02-25

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class boj_33516 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            switch (s.charAt(i)) {
                case 's':
                    stack.addLast(1);
                    break;

                case 'k':
                    if (!stack.isEmpty() && stack.peekLast() == 1) {
                        stack.addLast(stack.pollLast() + 1);
                    } else {
                        stack.clear();
                    }
                    break;

                case 'e':
                    if (!stack.isEmpty() && (stack.peekLast() == 2 || stack.peekLast() == 3)) {
                        stack.addLast(stack.pollLast() + 1);
                    } else {
                        stack.clear();
                    }
                    break;

                case 'p':
                    if (!stack.isEmpty() && stack.peekLast() == 4) {
                        stack.addLast(stack.pollLast() + 1);
                    } else {
                        stack.clear();
                    }
                    break;

                default:
                    stack.clear();
                    break;
            }

            while (!stack.isEmpty() && stack.peekLast() == 5) {
                stack.pollLast();
                ans++;

                if (!stack.isEmpty()) {
                    stack.addLast(stack.pollLast() + 1);
                }
            }
        }

        System.out.println(ans);
    }

}
