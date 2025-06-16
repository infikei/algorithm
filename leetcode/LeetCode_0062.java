// Solve 2025-06-15

class LeetCode_0062 {

    int recur(int x, int y, int m, int n, int[][] memo) {
        if (x >= m || y >= n) return 0;
        if (x == m - 1 && y == n - 1) return 1;
        if (memo[x][y] != 0) return memo[x][y];

        int ret = recur(x, y + 1, m, n, memo) + recur(x + 1, y, m, n, memo);
        return memo[x][y] = ret;
    }

    public int uniquePaths(int m, int n) {
        int[][] memo = new int[m][n];
        return recur(0, 0, m, n, memo);
    }

}
