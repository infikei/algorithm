// Solve 2026-05-19

import java.util.*;

class LC_1345 {

    public int minJumps(int[] arr) {
        int n = arr.length;
        TreeMap<Integer, ArrayList<Integer>> indexListByValue = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            ArrayList<Integer> curList = indexListByValue.get(arr[i]);

            if (curList == null) {
                curList = new ArrayList<>();
                indexListByValue.put(arr[i], curList);
            }

            curList.add(i);
        }

        boolean[] visited = new boolean[n];
        ArrayDeque<Integer> bfsQue = new ArrayDeque<>();
        visited[0] = true;
        bfsQue.addLast(0);
        int level = -1;

        while (!bfsQue.isEmpty()) {
            level++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                int curIdx = bfsQue.pollFirst();

                if (curIdx == n - 1) {
                    return level;
                }

                int curNum = arr[curIdx];
                ArrayList<Integer> nxtIndexList = indexListByValue.get(curNum);

                if (nxtIndexList != null) {
                    for (int nxtIdx : nxtIndexList) {
                        if (!visited[nxtIdx]) {
                            visited[nxtIdx] = true;
                            bfsQue.addLast(nxtIdx);
                        }
                    }

                    indexListByValue.remove(curNum);
                }

                if (curIdx - 1 >= 0 && !visited[curIdx - 1]) {
                    visited[curIdx - 1] = true;
                    bfsQue.addLast(curIdx - 1);
                }

                if (!visited[curIdx + 1]) {
                    visited[curIdx + 1] = true;
                    bfsQue.addLast(curIdx + 1);
                }
            }
        }

        return -1;
    }

}
