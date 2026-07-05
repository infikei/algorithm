// Solve 2026-06-21

import java.util.*;

class LC_1840 {

    public int maxBuilding(int n, int[][] restrictions) {
        ArrayList<int[]> restrictionList = new ArrayList<>();

        for (int[] restriction : restrictions) {
            restrictionList.add(restriction);
        }

        restrictionList.add(new int[] {1, 0});
        Collections.sort(restrictionList, (o1, o2) -> o1[0] - o2[0]);
        int mx = 0;

        for (int i = 1; i < restrictionList.size(); i++) {
            int[] prv = restrictionList.get(i - 1);
            int[] cur = restrictionList.get(i);
            cur[1] = Math.min(cur[1], prv[1] + (cur[0] - prv[0]));
        }

        for (int i = restrictionList.size() - 2; i >= 0; i--) {
            int[] nxt = restrictionList.get(i + 1);
            int[] cur = restrictionList.get(i);
            cur[1] = Math.min(cur[1], nxt[1] + (nxt[0] - cur[0]));
        }

        for (int i = 1; i < restrictionList.size(); i++) {
            int[] prv = restrictionList.get(i - 1);
            int[] cur = restrictionList.get(i);
            int top = Math.max(prv[1], cur[1]) + Math.max(0, (cur[0] - prv[0]) - Math.abs(cur[1] - prv[1])) / 2;
            mx = Math.max(mx, top);
        }

        int[] last = restrictionList.get(restrictionList.size() - 1);
        mx = Math.max(mx, last[1] + (n - last[0]));
        return mx;
    }

}
