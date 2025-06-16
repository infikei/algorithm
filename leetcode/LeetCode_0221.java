// Solve 2025-06-15

class LeetCode_0221 {

    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] memo = new int[m + 1][n + 1];
        int ret = 0;

        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= n; y++) {
                if (matrix[x - 1][y - 1] == '1') {
                    memo[x][y] = Math.min(memo[x][y - 1], Math.min(memo[x - 1][y - 1], memo[x - 1][y])) + 1;
                    ret = Math.max(ret, memo[x][y]);
                }
            }
        }

        return ret * ret;
    }

}
