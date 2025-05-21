// Solve 2025-05-21

import java.util.*;

class PG_118667_두_큐_합_같게_만들기 {

    public int solution(int[] queue1, int[] queue2) {
        ArrayDeque<Integer> que1 = new ArrayDeque<>();
        ArrayDeque<Integer> que2 = new ArrayDeque<>();
        long sumOfQue1 = 0;
        long sumOfQue2 = 0;

        for (int x : queue1) {
            que1.addLast(x);
            sumOfQue1 += x;
        }

        for (int x : queue2) {
            que2.addLast(x);
            sumOfQue2 += x;
        }

        if ((sumOfQue1 + sumOfQue2) % 2 == 1) {
            return -1;
        }

        int iter = 0;
        int maxIter = queue1.length * 4;

        while (iter < maxIter) {
            if (sumOfQue1 > sumOfQue2) {
                int cur = que1.pollFirst();
                que2.addLast(cur);
                sumOfQue1 -= cur;
                sumOfQue2 += cur;
            } else if (sumOfQue1 < sumOfQue2) {
                int cur = que2.pollFirst();
                que1.addLast(cur);
                sumOfQue2 -= cur;
                sumOfQue1 += cur;
            } else {
                return iter;
            }

            iter++;
        }

        return -1;
    }

}
