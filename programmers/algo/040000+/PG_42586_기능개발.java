// Solve 2025-04-16

import java.util.*;

class PG_42586_기능개발 {

    int getRemainingDays(int progress, int speed) {
        int remaining = 100 - progress;

        return (remaining - 1) / speed + 1;
    }

    public int[] solution(int[] progresses, int[] speeds) {
        ArrayDeque<int[]> deque = new ArrayDeque<int[]>();
        deque.addLast(new int[] { getRemainingDays(progresses[0], speeds[0]), 1 });

        for (int i = 1; i < progresses.length; i++) {
            int remainingDays = getRemainingDays(progresses[i], speeds[i]);

            if (deque.getLast()[0] >= remainingDays) {
                deque.getLast()[1]++;
            } else {
                deque.addLast(new int[] { remainingDays, 1 });
            }
        }

        int[] answer = new int[deque.size()];

        for (int i = 0; i < answer.length; i++) {
            answer[i] = deque.pollFirst()[1];
        }

        return answer;
    }

}
