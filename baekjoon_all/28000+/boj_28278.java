// Solve 2024-01-21
// Update 2025-04-28

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class boj_28278 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

        while (n-- > 0) {
            String cmd = br.readLine();

            switch (cmd.charAt(0)) {
                case '1':
                    int x = Integer.parseInt(cmd.substring(2));
                    stack.addLast(x);
                    break;

                case '2':
                    sb.append(stack.isEmpty() ? -1 : stack.pollLast()).append('\n');
                    break;

                case '3':
                    sb.append(stack.size()).append('\n');
                    break;

                case '4':
                    sb.append(stack.isEmpty() ? "1\n" : "0\n");
                    break;

                case '5':
                    sb.append(stack.isEmpty() ? -1 : stack.peekLast()).append('\n');
                    break;
            }
        }

        System.out.print(sb);
    }

}
