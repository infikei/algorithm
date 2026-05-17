// Solve 2026-05-17

class LC_0154_solution2 {

    public int findMin(int[] nums) {
        int mn = nums[0];

        for (int num : nums) {
            mn = num < mn ? num : mn;
        }

        return mn;
    }

}
