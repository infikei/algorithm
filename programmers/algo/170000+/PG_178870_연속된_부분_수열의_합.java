// Solve 2025-05-23

import java.util.*;

class PG_178870_연속된_부분_수열의_합 {

    public int[] solution(int[] sequence, int k) {
        ArrayList<int[]> answerList = new ArrayList<>();
        int i = 0;
        int j = 0;
        int curSum = sequence[0];

        while (true) {
            if (curSum > k) {
                curSum -= sequence[i];
                i++;
            } else if (curSum < k) {
                j++;

                if (j == sequence.length) break;

                curSum += sequence[j];
            } else {
                answerList.add(new int[] { j - i, i, j });
                curSum -= sequence[i];
                i++;
                j++;

                if (j == sequence.length) break;

                curSum += sequence[j];
            }
        }

        Collections.sort(answerList, (o1, o2) -> {
            if (o1[0] != o2[0]) return o1[0] - o2[0];
            return o1[1] - o2[1];
        });

        return new int[] { answerList.get(0)[1], answerList.get(0)[2] };
    }

}
