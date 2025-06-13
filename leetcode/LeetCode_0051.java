// Solve 2025-06-13

import java.util.*;

class LeetCode_0051 {

    void dfs(int x, int[] yArr, int n, List<List<String>> boards) {
        if (x == n) {
            List<String> board = new ArrayList<>();

            for (int px = 0; px < n; px++) {
                int py = yArr[px];
                StringBuilder sb = new StringBuilder();

                for (int j = 0; j < n; j++) {
                    sb.append(j == py ? 'Q' : '.');
                }

                board.add(sb.toString());
            }

            boards.add(board);
            return;
        }

        for (int y = 0; y < n; y++) {
            boolean possible = true;

            for (int px = 0; px < x; px++) {
                int py = yArr[px];

                if (y == py || x + y == px + py || x - y == px - py) {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            yArr[x] = y;
            dfs(x + 1, yArr, n, boards);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> boards = new ArrayList<>();
        int[] yArr = new int[n];
        dfs(0, yArr, n, boards);
        return boards;
    }

}
