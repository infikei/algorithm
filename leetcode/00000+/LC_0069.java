// Solve 2025-06-11
// Update 2025-12-05

class LeetCode_0069 {

    public int mySqrt(int x) {
        long ans = 0;

        while (ans * ans <= x) {
            ans++;
        }

        return (int) ans - 1;
    }

}
