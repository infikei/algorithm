// Solve 2026-06-10

class LC_3689 {

    public long maxTotalValue(int[] nums, int k) {
        int mx = 0;
        int mn = 1000000000;

        for (int num : nums) {
            mx = num > mx ? num : mx;
            mn = num < mn ? num : mn;
        }

        return (long) (mx - mn) * k;
    }

}
