// Solve 2026-06-21

class LC_1732 {

    public int largestAltitude(int[] gain) {
        int mx = 0;
        int al = 0;

        for (int g : gain) {
            al += g;
            mx = Math.max(mx, al);
        }

        return mx;
    }

}
