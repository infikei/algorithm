// Solve 2025-12-11

import java.util.*;

class LeetCode_3531 {

    public int countCoveredBuildings(int n, int[][] buildings) {
        int[] xMin = new int[n + 1];
        int[] xMax = new int[n + 1];
        int[] yMin = new int[n + 1];
        int[] yMax = new int[n + 1];

        Arrays.fill(xMin, n + 1);
        Arrays.fill(yMin, n + 1);

        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            xMin[y] = Math.min(xMin[y], x);
            xMax[y] = Math.max(xMax[y], x);
            yMin[x] = Math.min(yMin[x], y);
            yMax[x] = Math.max(yMax[x], y);
        }

        int coveredCount = 0;

        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            if (xMin[y] < x && x < xMax[y] && yMin[x] < y && y < yMax[x]) {
                coveredCount++;
            }
        }

        return coveredCount;
    }

}
