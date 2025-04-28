// Solve 2024-01-21
// Update 2025-04-28

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_28278_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] stack = new int[1_000_000];
        int stackSize = 0;

        while (n-- > 0) {
            String cmd = br.readLine();

            switch (cmd.charAt(0)) {
                case '1':
                    int x = Integer.parseInt(cmd.substring(2));
                    stack[stackSize++] = x;
                    break;

                case '2':
                    sb.append(stackSize == 0 ? -1 : stack[--stackSize]).append('\n');
                    break;

                case '3':
                    sb.append(stackSize).append('\n');
                    break;

                case '4':
                    sb.append(stackSize == 0 ? "1\n" : "0\n");
                    break;

                case '5':
                    sb.append(stackSize == 0 ? -1 : stack[stackSize - 1]).append('\n');
                    break;
            }
        }

        System.out.print(sb);
    }

}
