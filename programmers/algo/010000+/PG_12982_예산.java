// Solve 2025-04-16

import java.util.*;

class PG_12982_예산 {

    public int solution(int[] d, int budget) {
        Arrays.sort(d);

        int answer = 0;
        int curAmount = 0;

        for (int i = 0; i < d.length; i++) {
            if (curAmount + d[i] > budget) break;

            curAmount += d[i];
            answer++;
        }

        return answer;
    }

}
