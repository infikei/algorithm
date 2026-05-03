// Solve 2025-06-12

class LeetCode_0079 {

    static int[] dx = new int[] { 0, 0, -1, 1 };
    static int[] dy = new int[] { -1, 1, 0, 0 };

    boolean isInRange(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    boolean dfs(int depth, int x, int y, int n, int m, boolean[][] visited, char[][] board, String word) {
        if (depth + 1 == word.length()) return true;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (!isInRange(nx, ny, n, m)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] != word.charAt(depth + 1)) continue;

            visited[nx][ny] = true;
            if (dfs(depth + 1, nx, ny, n, m, visited, board, word)) return true;
            visited[nx][ny] = false;
        }

        return false;
    }

    public boolean exist(char[][] board, String word) {
        int n = board.length;
        int m = board[0].length;
        boolean[][] visited = new boolean[n][m];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (board[x][y] != word.charAt(0)) continue;

                visited[x][y] = true;
                if (dfs(0, x, y, n, m, visited, board, word)) return true;
                visited[x][y] = false;
            }
        }

        return false;
    }

}
