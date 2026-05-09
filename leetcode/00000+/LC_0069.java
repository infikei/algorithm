// Solve 2025-06-11
// Update 2026-05-09

class LC_0069 {

    public int mySqrt(int x) {
        long ans = 0;

        while (ans * ans <= x) {
            ans++;
        }

        return (int) ans - 1;
    }

}
