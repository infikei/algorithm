// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0062_solution2 {

    public int uniquePaths(int m, int n) {
        int[][] memo = new int[m][n];
        memo[0][0] = 1;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (x >= 1) memo[x][y] += memo[x - 1][y];
                if (y >= 1) memo[x][y] += memo[x][y - 1];
            }
        }

        return memo[m - 1][n - 1];
    }

}
