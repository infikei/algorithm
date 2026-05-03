// Solve 2025-12-07

class LeetCode_3432 {

    public int countPartitions(int[] nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        return sum % 2 == 0 ? nums.length - 1 : 0;
    }

}
