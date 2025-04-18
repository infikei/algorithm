// Solve 2025-03-18
// Update 2025-04-16

class LeetCode_2206 {

    public boolean divideArray(int[] nums) {
        int[] cntOfNums = new int[501];

        for (int num : nums) {
            cntOfNums[num]++;
        }

        for (int cnt : cntOfNums) {
            if (cnt % 2 == 1) {
                return false;
            }
        }

        return true;
    }

}
