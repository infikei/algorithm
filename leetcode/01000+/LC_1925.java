// Solve 2025-12-09
// Update 2026-05-09

class LC_1925 {

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
