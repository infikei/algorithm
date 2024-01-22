// Solve 2024-01-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_4949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String str = br.readLine();

            if (str.length() == 1 && str.charAt(0) == '.') {
                break;
            }

            boolean isBalanced = true;
            char[] stack = new char[str.length()];
            int stackSize = 0;

            for (int i = 0; i < str.length(); i++) {
                char ch = str.charAt(i);

                if (ch == '(' || ch == '[') {
                    stack[stackSize++] = ch;
                } else if (ch == ')') {
                    if (stackSize == 0 || stack[stackSize - 1] != '(') {
                        isBalanced = false;
                        break;
                    }

                    stackSize--;
                } else if (ch == ']') {
                    if (stackSize == 0 || stack[stackSize - 1] != '[') {
                        isBalanced = false;
                        break;
                    }

                    stackSize--;
                }
            }

            if (stackSize != 0) {
                isBalanced = false;
            }

            sb.append(isBalanced ? "yes\n" : "no\n");
        }

        System.out.println(sb);
        br.close();
    }
}
