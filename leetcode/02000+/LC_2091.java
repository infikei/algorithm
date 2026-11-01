// Solve 2026-08-30

class LC_2091 {

    public int minimumDeletions(int[] nums) {
        int n = nums.length;

        if (n == 1) {
            return 1;
        }

        int mx = nums[0];
        int a = 0;
        int mn = nums[0];
        int b = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                a = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                b = i;
            }
        }

        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        int ans = Math.min(a + 1 + n - b, Math.min(b + 1, n - a));
        return ans;
    }

}
