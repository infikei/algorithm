// Solve 2026-05-17

import java.util.*;

class LC_1306 {

    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean[] visited = new boolean[n];
        ArrayDeque<Integer> bfsQue = new ArrayDeque<>();
        visited[start] = true;
        bfsQue.addLast(start);

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.pollFirst();

            if (arr[cur] == 0) {
                return true;
            }

            if (cur - arr[cur] >= 0 && !visited[cur - arr[cur]]) {
                visited[cur - arr[cur]] = true;
                bfsQue.addLast(cur - arr[cur]);
            }

            if (cur + arr[cur] < n && !visited[cur + arr[cur]]) {
                visited[cur + arr[cur]] = true;
                bfsQue.addLast(cur + arr[cur]);
            }
        }

        return false;
    }

}