// Solve 2025-06-11

public class LeetCode_0069_solution2 {

    public int mySqrt(int x) {
        int low = -1;
        int high = 46341;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (mid * mid <= x) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }

}
