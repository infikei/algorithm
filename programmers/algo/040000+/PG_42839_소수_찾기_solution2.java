// Solve 2025-06-12

import java.util.*;

class PG_42839_소수_찾기_solution2 {

    void dfs(int curNum, boolean[] selected, Set<Integer> set, String numbers) {
        set.add(curNum);

        for (int i = 0; i < selected.length; i++) {
            if (selected[i]) continue;

            selected[i] = true;
            dfs(curNum * 10 + (numbers.charAt(i) - '0'), selected, set, numbers);
            selected[i] = false;
        }
    }

    boolean[] createSieve() {
        boolean[] sieve = new boolean[10000000];
        sieve[0] = sieve[1] = true;

        for (int i = 2; i < 10000000; i++) {
            if (sieve[i]) continue;

            for (int j = i + i; j < 10000000; j += i) {
                sieve[j] = true;
            }
        }

        return sieve;
    }

    public int solution(String numbers) {
        Set<Integer> set = new TreeSet<>();
        boolean[] selected = new boolean[numbers.length()];
        dfs(0, selected, set, numbers);
        
        boolean[] sieve = createSieve();
        int answer = 0;

        for (int num : set) {
            if (!sieve[num]) {
                answer++;
            }
        }

        return answer;
    }

}
