// Solve 2025-04-16

import java.util.*;

class LeetCode_0739 {

    static class TemperatureInfo {
        int temperature;
        int idx;

        TemperatureInfo(int temperature, int idx) {
            this.temperature = temperature;
            this.idx = idx;
        }
    }

    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        ArrayDeque<TemperatureInfo> stack = new ArrayDeque<TemperatureInfo>();

        for (int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && stack.getLast().temperature < temperatures[i]) {
                answer[stack.getLast().idx] = i - stack.getLast().idx;
                stack.pollLast();
            }

            stack.addLast(new TemperatureInfo(temperatures[i], i));
        }

        return answer;
    }

}
