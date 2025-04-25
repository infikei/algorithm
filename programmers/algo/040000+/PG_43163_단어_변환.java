// Solve 2025-04-24

import java.util.*;

class PG_43163_단어_변환 {

    public int solution(String begin, String target, String[] words) {
        // 주어진 단어들을 바탕으로 인접 리스트를 만든다.
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i <= words.length; i++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < words.length; i++) {
            if (areWordsSimilar(begin, words[i])) {
                adj.get(0).add(i + 1);
                adj.get(i + 1).add(0);
            }
        }

        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (areWordsSimilar(words[i], words[j])) {
                    adj.get(i + 1).add(j + 1);
                    adj.get(j + 1).add(i + 1);
                }
            }
        }

        // BFS를 수행한다.
        boolean[] visited = new boolean[words.length + 1];
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();

        visited[0] = true;
        bfsQue.addLast(0);

        int depth = 0;

        while (!bfsQue.isEmpty()) {
            depth++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                int cur = bfsQue.pollFirst();

                for (int nxt : adj.get(cur)) {
                    if (visited[nxt]) continue;

                    if (words[nxt - 1].equals(target)) {
                        return depth;
                    }

                    visited[nxt] = true;
                    bfsQue.addLast(nxt);
                }
            }
        }

        return 0;
    }

    boolean areWordsSimilar(String s1, String s2) {
        int sameCharCnt = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == s2.charAt(i)) {
                sameCharCnt++;
            }
        }

        return sameCharCnt == s1.length() - 1;
    }

}
