// Solve 2025-06-12

import java.util.*;

class PG_42839_소수_찾기 {

    void dfs(int curNum, boolean[] selected, Set<Integer> set, String numbers) {
        set.add(curNum);

        for (int i = 0; i < selected.length; i++) {
            if (selected[i]) continue;

            selected[i] = true;
            dfs(curNum * 10 + (numbers.charAt(i) - '0'), selected, set, numbers);
            selected[i] = false;
        }
    }

    boolean isPrime(int num) {
        if (num <= 1) return false;

        for (int i = 2; i * i <= num; i++) { // i <= Math.sqrt(num)
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    public int solution(String numbers) {
        Set<Integer> set = new TreeSet<>();
        boolean[] selected = new boolean[numbers.length()];
        dfs(0, selected, set, numbers);

        int answer = 0;

        for (int num : set) {
            if (isPrime(num)) {
                answer++;
            }
        }

        return answer;
    }

}
