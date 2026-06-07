// Solve 2026-06-07

class LC_2574 {

    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] prefixSum = new int[n];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int[] suffixSum = new int[n];

        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + nums[i + 1];
        }

        int[] answer = new int[n];

        for (int i = 0; i < n; i++) {
            answer[i] = Math.abs(prefixSum[i] - suffixSum[i]);
        }

        return answer;
    }

}
