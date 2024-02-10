// Solve 2024-02-09

// 코드트리에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class tree_kill_all {

    static int[] dx = { -1, 0, 0, 1, -1, -1, 1, 1 };
    static int[] dy = { 0, -1, 1, 0, -1, 1, -1, 1 };
    static int n, m, k, c;
    static int[][] board;
    static int[][] treeKillerBoard;
    static int ans;

    static void growTree() {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] <= 0) continue;

                int treeToAdd = 0;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] > 0) {
                        treeToAdd++;
                    }
                }

                board[x][y] += treeToAdd;
            }
        }
    }

    static void spreadTree() {
        int[][] newBoard = new int[n][n];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] != 0) {
                    newBoard[x][y] = board[x][y];
                }

                if (board[x][y] <= 0) {
                    continue;
                }

                int aroundBlank = 0;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0) {
                        aroundBlank++;
                    }
                }

                if (aroundBlank == 0) continue;

                int treeToAdd = board[x][y] / aroundBlank;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0) {
                        newBoard[nx][ny] += treeToAdd;
                    }
                }
            }
        }

        board = null;
        board = newBoard;
    }

    static int killTree(int treeKillerYear) {
        int maxX = 0;
        int maxY = 0;
        int maxTreeToKill = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] <= 0) continue;

                int curTreeToKill = board[x][y];

                for (int d = 4; d < 8; d++) {
                    int nx = x;
                    int ny = y;

                    for (int i = 1; i <= k; i++) {
                        nx += dx[d];
                        ny += dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] <= 0) break;

                        curTreeToKill += board[nx][ny];
                    }
                }

                if (curTreeToKill > maxTreeToKill) {
                    maxTreeToKill = curTreeToKill;
                    maxX = x;
                    maxY = y;
                }
            }
        }

        board[maxX][maxY] = -2;
        treeKillerBoard[maxX][maxY] = treeKillerYear;

        for (int d = 4; d < 8; d++) {
            int nx = maxX;
            int ny = maxY;

            for (int i = 1; i <= k; i++) {
                nx += dx[d];
                ny += dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;

                if (board[nx][ny] == -2) {
                    treeKillerBoard[nx][ny] = treeKillerYear;
                    break;
                } else if (board[nx][ny] == -1) {
                    break;
                } else if (board[nx][ny] == 0) {
                    board[nx][ny] = -2;
                    treeKillerBoard[nx][ny] = treeKillerYear;
                    break;
                } else {
                    board[nx][ny] = -2;
                    treeKillerBoard[nx][ny] = treeKillerYear;
                }
            }
        }

        return maxTreeToKill;
    }

    static void removeTreeKiller(int nowYear) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (treeKillerBoard[x][y] == nowYear) {
                    treeKillerBoard[x][y] = 0;
                    board[x][y] = 0;
                }
            }
        }
    }

    static void printBoard() {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                System.out.print(board[x][y] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        board = new int[n][n];
        treeKillerBoard = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int mi = 1; mi <= m; mi++) {
            growTree();
            spreadTree();
            ans += killTree(mi + c);
            removeTreeKiller(mi);
        }

        System.out.println(ans);
        br.close();
    }

}
