// Solve 2025-04-16
// Update 2025-05-03

import java.util.*;

class LeetCode_0739 {

    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

        for (int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && temperatures[stack.getLast()] < temperatures[i]) {
                answer[stack.getLast()] = i - stack.getLast();
                stack.pollLast();
            }

            stack.addLast(i);
        }

        return answer;
    }

}
