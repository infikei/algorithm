// Solve 2025-12-08
// Update 2026-05-09

class LC_1523 {

    public int countOdds(int low, int high) {
        if (low % 2 == 0 && high % 2 == 0) {
            return (high - low) / 2;
        }

        return (high - low) / 2 + 1;
    }

}
