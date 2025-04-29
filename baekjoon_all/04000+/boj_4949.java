// Solve 2024-01-21
// Update 2025-04-29

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_4949 {

    static boolean checkValidParentheses(String s) {
        char[] stack = new char[s.length()];
        int stackSize = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            switch (c) {
                case '(':
                case '[':
                    stack[stackSize++] = c;
                    break;

                case ')':
                    if (stackSize == 0 || stack[stackSize - 1] != '(') return false;

                    stackSize--;
                    break;

                case ']':
                    if (stackSize == 0 || stack[stackSize - 1] != '[') return false;

                    stackSize--;
                    break;
            }
        }

        return stackSize == 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String sentence = br.readLine();

            if (sentence.length() == 1 && sentence.charAt(0) == '.') break;

            sb.append(checkValidParentheses(sentence) ? "yes\n" : "no\n");
        }

        System.out.print(sb);
    }

}
