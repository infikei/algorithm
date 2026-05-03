// Solve 2025-12-09

public class LeetCode_1925 {

    public int countTriples(int n) {
        int ret = 0;

        for (int c = 1; c <= n; c++) {
            for (int b = 1; b < c; b++) {
                int a2 = c * c - b * b;
                int a = (int) Math.round(Math.sqrt(a2));

                if (a * a == a2) {
                    ret++;
                }
            }
        }

        return ret;
    }

}
