// Solve 2026-06-03

class LC_3633 {

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int n = landStartTime.length;
        int m = waterStartTime.length;
        int mn = 1000000;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val1 = Math.max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j];
                int val2 = Math.max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i];
                mn = Math.min(mn, Math.min(val1, val2));
            }
        }

        return mn;
    }

}
