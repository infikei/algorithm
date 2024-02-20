// Solve 2024-02-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15683 {

    static class CCTV {
        int x, y, type;

        CCTV(int x, int y, int type) {
            this.x = x;
            this.y = y;
            this.type = type;
        }
    }

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static CCTV[] cctvs = new CCTV[8];
    static int cctvCount = 0;
    static int minHiddenArea;

    static void dfs(int depth, int[][] board, int hiddenArea) {
        if (depth == cctvCount) {
            minHiddenArea = Math.min(minHiddenArea, hiddenArea);
            return;
        }

        int n = board.length;
        int m = board[0].length;

        if (cctvs[depth].type == 1) {
            for (int d = 0; d < 4; d++) {
                int[][] newBoard = copyBoard(board);
                int newHiddenArea = hiddenArea;
                int curX = cctvs[depth].x + dx[d];
                int curY = cctvs[depth].y + dy[d];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[d];
                    curY += dy[d];
                }

                dfs(depth + 1, newBoard, newHiddenArea);
            }
        } else if (cctvs[depth].type == 2) {
            for (int d = 0; d < 2; d++) {
                int[][] newBoard = copyBoard(board);
                int newHiddenArea = hiddenArea;
                int curX = cctvs[depth].x + dx[d];
                int curY = cctvs[depth].y + dy[d];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[d];
                    curY += dy[d];
                }

                int nd = d + 2;
                curX = cctvs[depth].x + dx[nd];
                curY = cctvs[depth].y + dy[nd];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[nd];
                    curY += dy[nd];
                }

                dfs(depth + 1, newBoard, newHiddenArea);
            }
        } else if (cctvs[depth].type == 3) {
            for (int d = 0; d < 4; d++) {
                int[][] newBoard = copyBoard(board);
                int newHiddenArea = hiddenArea;
                int curX = cctvs[depth].x + dx[d];
                int curY = cctvs[depth].y + dy[d];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[d];
                    curY += dy[d];
                }

                int nd = (d + 1) % 4;
                curX = cctvs[depth].x + dx[nd];
                curY = cctvs[depth].y + dy[nd];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[nd];
                    curY += dy[nd];
                }

                dfs(depth + 1, newBoard, newHiddenArea);
            }
        } else if (cctvs[depth].type == 4) {
            for (int d = 0; d < 4; d++) {
                int[][] newBoard = copyBoard(board);
                int newHiddenArea = hiddenArea;
                int curX = cctvs[depth].x + dx[d];
                int curY = cctvs[depth].y + dy[d];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[d];
                    curY += dy[d];
                }

                int nd = (d + 1) % 4;
                curX = cctvs[depth].x + dx[nd];
                curY = cctvs[depth].y + dy[nd];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[nd];
                    curY += dy[nd];
                }

                nd = (nd + 1) % 4;
                curX = cctvs[depth].x + dx[nd];
                curY = cctvs[depth].y + dy[nd];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[nd];
                    curY += dy[nd];
                }

                dfs(depth + 1, newBoard, newHiddenArea);
            }
        } else {
            int[][] newBoard = copyBoard(board);
            int newHiddenArea = hiddenArea;

            for (int d = 0; d < 4; d++) {
                int curX = cctvs[depth].x + dx[d];
                int curY = cctvs[depth].y + dy[d];

                while (true) {
                    if (curX < 0 || curX >= n || curY < 0 || curY >= m || newBoard[curX][curY] == 6) break;
                    if (newBoard[curX][curY] == 0) {
                        newBoard[curX][curY] = 7;
                        newHiddenArea--;
                    }

                    curX += dx[d];
                    curY += dy[d];
                }
            }

            dfs(depth + 1, newBoard, newHiddenArea);
        }
    }

    static int[][] copyBoard(int[][] board) {
        int n = board.length;
        int m = board[0].length;
        int[][] newBoard = new int[n][m];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                newBoard[x][y] = board[x][y];
            }
        }

        return newBoard;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int hiddenArea = 0;

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';

                if (board[x][y] == 0) {
                    hiddenArea++;
                } else if (board[x][y] <= 5) {
                    cctvs[cctvCount++] = new CCTV(x, y, board[x][y]);
                }
            }
        }

        minHiddenArea = hiddenArea;
        dfs(0, board, hiddenArea);
        System.out.println(minHiddenArea);
        br.close();
    }

}
