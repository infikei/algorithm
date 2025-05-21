// Solve 2025-05-21

import java.util.*;

class PG_76502_괄호_회전하기 {

    public int solution(String s) {
        int answer = 0;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            s = s.substring(1, len) + s.charAt(0);

            if (isValidParentheses(s)) {
                answer++;
            }
        }

        return answer;
    }

    boolean isValidParentheses(String parentheses) {
        ArrayDeque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < parentheses.length(); i++) {
            char par = parentheses.charAt(i);

            switch (par) {
                case '(':
                case '{':
                case '[':
                    stack.addLast(par);
                    break;
                case ')':
                    if (stack.isEmpty() || stack.pollLast() != '(') {
                        return false;
                    }
                    break;
                case '}':
                    if (stack.isEmpty() || stack.pollLast() != '{') {
                        return false;
                    }
                    break;
                case ']':
                    if (stack.isEmpty() || stack.pollLast() != '[') {
                        return false;
                    }
                    break;
            }
        }

        return stack.isEmpty();
    }

}
