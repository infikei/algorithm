// Solve 2025-04-29

class PG_92344_파괴되지_않은_건물 {

    public int solution(int[][] board, int[][] skill) {
        int n = board.length;
        int m = board[0].length;
        int[][] degreeBoard = new int[n + 1][m + 1];

        for (int[] ski : skill) {
            int degree = (ski[0] == 1 ? -ski[5] : ski[5]);
            int r1 = ski[1];
            int c1 = ski[2];
            int r2 = ski[3];
            int c2 = ski[4];

            degreeBoard[r1][c1] += degree;
            degreeBoard[r1][c2 + 1] -= degree;
            degreeBoard[r2 + 1][c1] -= degree;
            degreeBoard[r2 + 1][c2 + 1] += degree;
        }

        for (int y = 1; y < m; y++) {
            degreeBoard[0][y] += degreeBoard[0][y - 1];
        }

        for (int x = 1; x < n; x++) {
            degreeBoard[x][0] += degreeBoard[x - 1][0];

            for (int y = 1; y < m; y++) {
                degreeBoard[x][y] += degreeBoard[x][y - 1] + degreeBoard[x - 1][y] - degreeBoard[x - 1][y - 1];
            }
        }

        int answer = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (board[x][y] + degreeBoard[x][y] >= 1) {
                    answer++;
                }
            }
        }

        return answer;
    }

}
