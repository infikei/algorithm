// Solve 2026-05-09

class LC_1914 {

    void rotateLayer(int[][] grid, int xs, int xe, int ys, int ye) {
        int tmp = grid[xs][ys];

        for (int j = ys + 1; j <= ye; j++) {
            grid[xs][j - 1] = grid[xs][j];
        }

        for (int i = xs + 1; i <= xe; i++) {
            grid[i - 1][ye] = grid[i][ye];
        }

        for (int j = ye - 1; j >= ys; j--) {
            grid[xe][j + 1] = grid[xe][j];
        }

        for (int i = xe - 1; i >= xs; i--) {
            grid[i + 1][ys] = grid[i][ys];
        }

        grid[xs + 1][ys] = tmp;
    }

    public int[][] rotateGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int xs = 0;
        int xe = m - 1;
        int ys = 0;
        int ye = n - 1;

        while (xs < xe && ys < ye) {
            int nElem = (xe - xs + ye - ys) * 2;
            int iterRotate = k % nElem;

            while (iterRotate-- > 0) {
                rotateLayer(grid, xs, xe, ys, ye);
            }

            xs++;
            xe--;
            ys++;
            ye--;
        }

        return grid;
    }

}
