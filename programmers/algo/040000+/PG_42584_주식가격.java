// Solve 2025-04-16
// Update 2025-05-03

import java.util.*;

class PG_42584_주식가격 {

    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

        for (int i = 0; i < prices.length; i++) {
            while (!stack.isEmpty() && prices[stack.getLast()] > prices[i]) {
                answer[stack.getLast()] = i - stack.getLast();
                stack.pollLast();
            }

            stack.addLast(i);
        }

        while (!stack.isEmpty()) {
            answer[stack.getLast()] = prices.length - 1 - stack.getLast();
            stack.pollLast();
        }

        return answer;
    }

}
