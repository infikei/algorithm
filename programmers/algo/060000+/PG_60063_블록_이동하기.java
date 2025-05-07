// Solve 2025-05-06

import java.util.*;

class PG_60063_블록_이동하기 {

    static class Point {
        int x, y, d;

        Point(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }

    public int solution(int[][] board) {
        int n = board.length;

        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        boolean[][][] visited = new boolean[n][n][2];
        visited[0][1][0] = true;
        bfsQue.addLast(new Point(0, 1, 0));
        int depth = 0;

        while (!bfsQue.isEmpty()) {
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point curPos = bfsQue.pollFirst();

                if (curPos.x == n - 1 && curPos.y == n - 1) return depth;

                if (curPos.d == 0) {
                    moveFromGaro(n, board, visited, bfsQue, curPos.x, curPos.y);
                } else {
                    moveFromSero(n, board, visited, bfsQue, curPos.x, curPos.y);
                }
            }

            depth++;
        }

        return -1;
    }

    void moveFromGaro(int n, int[][] board, boolean[][][] visited, ArrayDeque<Point> bfsQue, int x, int y) {
        if (y - 2 >= 0 && board[x][y - 2] == 0 && !visited[x][y - 1][0]) {
            visited[x][y - 1][0] = true;
            bfsQue.addLast(new Point(x, y - 1, 0));
        }

        if (y + 1 < n && board[x][y + 1] == 0 && !visited[x][y + 1][0]) {
            visited[x][y + 1][0] = true;
            bfsQue.addLast(new Point(x, y + 1, 0));
        }

        if (x - 1 >= 0 && board[x - 1][y] == 0 && board[x - 1][y - 1] == 0) {
            if (!visited[x - 1][y][0]) {
                visited[x - 1][y][0] = true;
                bfsQue.addLast(new Point(x - 1, y, 0));
            }

            if (!visited[x][y - 1][1]) {
                visited[x][y - 1][1] = true;
                bfsQue.addLast(new Point(x, y - 1, 1));
            }

            if (!visited[x][y][1]) {
                visited[x][y][1] = true;
                bfsQue.addLast(new Point(x, y, 1));
            }
        }

        if (x + 1 < n && board[x + 1][y] == 0 && board[x + 1][y - 1] == 0) {
            if (!visited[x + 1][y][0]) {
                visited[x + 1][y][0] = true;
                bfsQue.addLast(new Point(x + 1, y, 0));
            }

            if (!visited[x + 1][y - 1][1]) {
                visited[x + 1][y - 1][1] = true;
                bfsQue.addLast(new Point(x + 1, y - 1, 1));
            }

            if (!visited[x + 1][y][1]) {
                visited[x + 1][y][1] = true;
                bfsQue.addLast(new Point(x + 1, y, 1));
            }
        }
    }

    void moveFromSero(int n, int[][] board, boolean[][][] visited, ArrayDeque<Point> bfsQue, int x, int y) {
        if (x - 2 >= 0 && board[x - 2][y] == 0 && !visited[x - 1][y][1]) {
            visited[x - 1][y][1] = true;
            bfsQue.addLast(new Point(x - 1, y, 1));
        }

        if (x + 1 < n && board[x + 1][y] == 0 && !visited[x + 1][y][1]) {
            visited[x + 1][y][1] = true;
            bfsQue.addLast(new Point(x + 1, y, 1));
        }

        if (y - 1 >= 0 && board[x][y - 1] == 0 && board[x - 1][y - 1] == 0) {
            if (!visited[x][y - 1][1]) {
                visited[x][y - 1][1] = true;
                bfsQue.addLast(new Point(x, y - 1, 1));
            }

            if (!visited[x - 1][y][0]) {
                visited[x - 1][y][0] = true;
                bfsQue.addLast(new Point(x - 1, y, 0));
            }

            if (!visited[x][y][0]) {
                visited[x][y][0] = true;
                bfsQue.addLast(new Point(x, y, 0));
            }
        }

        if (y + 1 < n && board[x][y + 1] == 0 && board[x - 1][y + 1] == 0) {
            if (!visited[x][y + 1][1]) {
                visited[x][y + 1][1] = true;
                bfsQue.addLast(new Point(x, y + 1, 1));
            }

            if (!visited[x - 1][y + 1][0]) {
                visited[x - 1][y + 1][0] = true;
                bfsQue.addLast(new Point(x - 1, y + 1, 0));
            }

            if (!visited[x][y + 1][0]) {
                visited[x][y + 1][0] = true;
                bfsQue.addLast(new Point(x, y + 1, 0));
            }
        }
    }

}
