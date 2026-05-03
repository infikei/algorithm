// Solve 2025-04-16

import java.util.*;

class LeetCode_0020 {

    public boolean isValid(String s) {
        ArrayDeque<Character> stack = new ArrayDeque<Character>();

        for (int i = 0; i < s.length(); i++) {
            char par = s.charAt(i);

            switch (par) {
                case ')':
                    if (stack.isEmpty() || stack.getLast() != '(') {
                        return false;
                    }

                    stack.pollLast();
                    break;
                case '}':
                    if (stack.isEmpty() || stack.getLast() != '{') {
                        return false;
                    }

                    stack.pollLast();
                    break;
                case ']':
                    if (stack.isEmpty() || stack.getLast() != '[') {
                        return false;
                    }

                    stack.pollLast();
                    break;
                case '(':
                case '{':
                case '[':
                    stack.addLast(par);
                    break;
            }
        }

        return stack.isEmpty();
    }

}
