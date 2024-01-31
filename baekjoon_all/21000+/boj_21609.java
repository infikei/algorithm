// Solve 2024-01-30

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_21609 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Group implements Comparable<Group> {
        List<Point> blocks;
        int x, y;
        int rainbow;

        Group(int x, int y) {
            this.blocks = new ArrayList<>();
            this.x = x;
            this.y = y;
            this.rainbow = 0;
        }

        @Override
        public int compareTo(Group o) {
            if (blocks.size() != o.blocks.size()) return o.blocks.size() - blocks.size();
            if (rainbow != o.rainbow) return o.rainbow - rainbow;
            if (x != o.x) return o.x - x;

            return o.y - y;
        }
    }

    static final int EMPTY = -2;
    static final int BLACK = -1;
    static final int RAINBOW = 0;
    static int n, m;
    static int[][] board;
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n][n];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int scoreSum = 0;

        while (true) {
            boolean[][] visited = new boolean[n][n];
            Group maxGroup = null;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (board[x][y] <= RAINBOW || visited[x][y]) continue;

                    boolean[][] visited2 = new boolean[n][n];
                    Group curGroup = new Group(x, y);
                    int blocksIter = 0;
                    visited[x][y] = true;
                    visited2[x][y] = true;
                    curGroup.blocks.add(new Point(x, y));

                    while (blocksIter != curGroup.blocks.size()) {
                        Point curBlock = curGroup.blocks.get(blocksIter++);

                        for (int d = 0; d < 4; d++) {
                            int nx = curBlock.x + dx[d];
                            int ny = curBlock.y + dy[d];

                            if (!isInBoard(nx, ny) || visited2[nx][ny]) continue;

                            if (board[nx][ny] == RAINBOW) {
                                visited2[nx][ny] = true;
                                curGroup.blocks.add(new Point(nx, ny));
                                curGroup.rainbow++;
                            } else if (board[nx][ny] == board[x][y]) {
                                visited[nx][ny] = true;
                                visited2[nx][ny] = true;
                                curGroup.blocks.add(new Point(nx, ny));
                            }
                        }
                    }

                    if (curGroup.blocks.size() < 2) continue;

                    if (maxGroup == null) {
                        maxGroup = curGroup;
                    } else if (maxGroup.compareTo(curGroup) > 0) {
                        maxGroup = curGroup;
                    }
                }
            }

            if (maxGroup == null) break;

            scoreSum += maxGroup.blocks.size() * maxGroup.blocks.size();

            for (Point p : maxGroup.blocks) {
                board[p.x][p.y] = EMPTY;
            }

            applyGravity();
            rotate();
            applyGravity();
        }

        System.out.println(scoreSum);
    }

    static boolean isInBoard(int x, int y) {
        return x >= 0 & x < n && y >= 0 && y < n;
    }

    static void rotate() {
        int[][] newBoard = new int[n][n];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                newBoard[x][y] = board[y][n - 1 - x];
            }
        }

        board = null;
        board = newBoard;
    }

    static void applyGravity() {
        for (int y = 0; y < n; y++) {
            for (int x = n - 1; x >= 1; x--) {
                if (board[x][y] != EMPTY) continue;

                int nx = x - 1;

                while (nx >= 0 && board[nx][y] == EMPTY) {
                    nx--;
                }

                if (nx < 0 || board[nx][y] == BLACK) continue;

                board[x][y] = board[nx][y];
                board[nx][y] = EMPTY;
            }
        }
    }

}
