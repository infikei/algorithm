// Solve 2024-01-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj_28278_solution1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();

        while (n-- > 0) {
            String query = br.readLine();
            char cmd = query.charAt(0);

            if (cmd == '1') {
                int x = Integer.parseInt(query.substring(2));
                stack.push(x);
            } else if (cmd == '2') {
                sb.append(stack.empty() ? -1 : stack.pop()).append("\n");
            } else if (cmd == '3') {
                sb.append(stack.size()).append("\n");
            } else if (cmd == '4') {
                sb.append(stack.empty() ? 1 : 0).append("\n");
            } else {
                sb.append(stack.empty() ? -1 : stack.peek()).append("\n");
            }
        }

        System.out.println(sb);
        br.close();
    }
}
