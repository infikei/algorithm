// Solve 2026-05-16

class LC_0153 {

    public int findMin(int[] nums) {
        int n = nums.length;

        if (nums[0] <= nums[n - 1]) {
            return nums[0];
        }

        int left = 0;
        int right = n - 1;

        while (left + 1 < right) {
            int mid = (left + right) / 2;

            if (nums[left] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return nums[right];
    }

}
