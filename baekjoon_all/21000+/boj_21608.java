// Solve 2024-03-11

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_21608 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int n2 = n * n;
        int[][] info = new int[n2][7];

        for (int i = 0; i < n2; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < 5; j++) {
                info[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] board = new int[n][n];

        for (int i = 0; i < n2; i++) {
            int maxX = 0;
            int maxY = 0;
            int maxFavoriteCount = -1;
            int maxEmptyCount = -1;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (board[x][y] != 0) continue;

                    int curFavoriteCount = 0;
                    int curEmptyCount = 0;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        } else if (board[nx][ny] == 0) {
                            curEmptyCount++;
                        } else {
                            for (int j = 1; j <= 4; j++) {
                                if (board[nx][ny] == info[i][j]) {
                                    curFavoriteCount++;
                                    break;
                                }
                            }
                        }
                    }

                    boolean flagUpdate = false;

                    if (curFavoriteCount > maxFavoriteCount) {
                        flagUpdate = true;
                    } else if (curFavoriteCount == maxFavoriteCount && curEmptyCount > maxEmptyCount) {
                        flagUpdate = true;
                    }

                    if (flagUpdate) {
                        maxX = x;
                        maxY = y;
                        maxFavoriteCount = curFavoriteCount;
                        maxEmptyCount = curEmptyCount;
                    }
                }
            }

            board[maxX][maxY] = info[i][0];
            info[i][5] = maxX;
            info[i][6] = maxY;
        }

        int ans = 0;

        for (int i = 0; i < n2; i++) {
            int x = info[i][5];
            int y = info[i][6];
            int curFavoriteCount = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                for (int j = 1; j <= 4; j++) {
                    if (board[nx][ny] == info[i][j]) {
                        curFavoriteCount++;
                    }
                }
            }

            if (curFavoriteCount == 1) {
                ans++;
            } else if (curFavoriteCount == 2) {
                ans += 10;
            } else if (curFavoriteCount == 3) {
                ans += 100;
            } else if (curFavoriteCount == 4) {
                ans += 1000;
            }
        }

        System.out.println(ans);
    }

}
