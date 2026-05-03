// Solve 2025-06-15
// Update 2025-06-19

class LeetCode_0062_solution3 {

    public int uniquePaths(int m, int n) {
        int[][] memo = new int[m][n];

        for (int x = 0; x < m; x++) {
            memo[x][0] = 1;
        }

        for (int y = 0; y < n; y++) {
            memo[0][y] = 1;
        }


        for (int x = 1; x < m; x++) {
            for (int y = 1; y < n; y++) {
                memo[x][y] = memo[x - 1][y] + memo[x][y - 1];
            }
        }

        return memo[m - 1][n - 1];
    }

}
