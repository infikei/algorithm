// Solve 2026-05-17

class LC_0154 {

    public int findMin(int[] nums) {
        int n = nums.length;

        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int left = 0;
        int right = n - 1;

        while (left + 1 < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                left = mid;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }

        return Math.min(nums[left], nums[right]);
    }

}
