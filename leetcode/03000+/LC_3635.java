// Solve 2026-06-03

class LC_3635 {

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int n = landStartTime.length;
        int m = waterStartTime.length;
        int mn = 10000000;

        int minLandFinishTime = 10000000;

        for (int i = 0; i < n; i++) {
            minLandFinishTime = Math.min(minLandFinishTime, landStartTime[i] + landDuration[i]);
        }

        for (int j = 0; j < m; j++) {
            mn = Math.min(mn, Math.max(minLandFinishTime, waterStartTime[j]) + waterDuration[j]);
        }

        int minWaterFinishTime = 10000000;

        for (int j = 0; j < m; j++) {
            minWaterFinishTime = Math.min(minWaterFinishTime, waterStartTime[j] + waterDuration[j]);
        }

        for (int i = 0; i < n; i++) {
            mn = Math.min(mn, Math.max(minWaterFinishTime, landStartTime[i]) + landDuration[i]);
        }

        return mn;
    }

}
