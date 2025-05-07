// Solve 2025-05-03

class LeetCode_0200_solution2 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int numOfIslands = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (!visited[x][y] && grid[x][y] == '1') {
                    numOfIslands++;
                    dfs(grid, visited, x, y);
                }
            }
        }

        return numOfIslands;
    }

    void dfs(char[][] grid, boolean[][] visited, int x, int y) {
        visited[x][y] = true;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < grid.length && ny >= 0 & ny < grid[0].length && !visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(grid, visited, nx, ny);
            }
        }
    }

}
