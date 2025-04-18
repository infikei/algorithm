// Solve 2025-04-16

import java.util.*;

class PG_42584_주식가격 {

    static class PriceInfo {
        int price;
        int idx;

        PriceInfo(int price, int idx) {
            this.price = price;
            this.idx = idx;
        }
    }

    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        ArrayDeque<PriceInfo> stack = new ArrayDeque<PriceInfo>();

        for (int i = 0; i < prices.length; i++) {
            while (!stack.isEmpty() && stack.getLast().price > prices[i]) {
                answer[stack.getLast().idx] = i - stack.getLast().idx;
                stack.pollLast();
            }

            stack.addLast(new PriceInfo(prices[i], i));
        }

        while (!stack.isEmpty()) {
            answer[stack.getLast().idx] = prices.length - 1 - stack.getLast().idx;
            stack.pollLast();
        }

        return answer;
    }

}
