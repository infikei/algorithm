// Solve 2024-04-09

// 코드트리에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 메이즈_러너 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];
        int[][] newBoard = new int[n][n];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        Point[] players = new Point[m + 1]; // 0번째 인덱스에는 출구의 위치를 저장한다.

        for (int u = 1; u <= m; u++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            players[u] = new Point(x, y);
        }

        st = new StringTokenizer(br.readLine(), " ");
        int ex = Integer.parseInt(st.nextToken()) - 1;
        int ey = Integer.parseInt(st.nextToken()) - 1;
        players[0] = new Point(ex, ey);

        int movedDistSum = 0;
        int escapedCnt = 0;

        for (int i = 0; i < k; i++) {
            // 미로를 탈출하지 못한 모든 참가자를 이동시킨다.

            for (int u = 1; u <= m; u++) {
                if (players[u] == null) {
                    continue;
                } else if (players[u].x > players[0].x && board[players[u].x - 1][players[u].y] == 0) {
                    players[u].x--;
                    movedDistSum++;
                } else if (players[u].x < players[0].x && board[players[u].x + 1][players[u].y] == 0) {
                    players[u].x++;
                    movedDistSum++;
                } else if (players[u].y > players[0].y && board[players[u].x][players[u].y - 1] == 0) {
                    players[u].y--;
                    movedDistSum++;
                } else if (players[u].y < players[0].y && board[players[u].x][players[u].y + 1] == 0) {
                    players[u].y++;
                    movedDistSum++;
                }

                // 참가자의 현재 위치가 출구의 위치와 같다면 해당 참가자를 배열에서 제외한다.

                if (players[u].x == players[0].x && players[u].y == players[0].y) {
                    players[u] = null;
                    escapedCnt++;
                }
            }

            // 모든 참가자가 탈출했다면 게임을 종료한다.

            if (escapedCnt == m) {
                break;
            }

            // 출구와 한 명 이상의 참가자를 포함하는 정사각형 크기의 최솟값을 찾는다.

            int minSquareSize = 10000;

            for (int u = 1; u <= m; u++) {
                if (players[u] == null) {
                    continue;
                }

                int curSquareSize = Math.max(Math.abs(players[u].x - players[0].x), Math.abs(players[u].y - players[0].y));
                minSquareSize = curSquareSize < minSquareSize ? curSquareSize : minSquareSize;
            }

            minSquareSize++;
            int sx = 0;
            int sy = 0;

            for (sx = players[0].x - minSquareSize + 1; sx <= players[0].x; sx++) {
                if (sx < 0 || sx + minSquareSize > n) continue;

                boolean valid = false;

                for (sy = players[0].y - minSquareSize + 1; sy <= players[0].y; sy++) {
                    if (sy < 0 || sy + minSquareSize > n) continue;

                    for (int u = 1; u <= m; u++) {
                        if (players[u] == null) continue;

                        int px = players[u].x;
                        int py = players[u].y;

                        if (px >= sx && px < sx + minSquareSize && py >= sy && py < sy + minSquareSize) {
                            valid = true;
                            break;
                        }
                    }

                    if (valid) break;
                }

                if (valid) break;
            }

            // 정사각형 영역을 시계방향으로 90도 회전한다.

            for (int dx = 0; dx < minSquareSize; dx++) {
                for (int dy = 0; dy < minSquareSize; dy++) {
                    newBoard[sx + dx][sy + dy] = board[sx + minSquareSize - 1 - dy][sy + dx];
                }
            }

            for (int x = sx; x < sx + minSquareSize; x++) {
                for (int y = sy; y < sy + minSquareSize; y++) {
                    board[x][y] = newBoard[x][y] == 0 ? 0 : newBoard[x][y] - 1;
                }
            }

            for (int u = 0; u <= m; u++) {
                if (players[u] == null) {
                    continue;
                }

                int px = players[u].x;
                int py = players[u].y;

                if (px >= sx && px < sx + minSquareSize && py >= sy && py < sy + minSquareSize) {
                    players[u].x = sx + (py - sy);
                    players[u].y = sy + minSquareSize - 1 - (px - sx);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(movedDistSum).append("\n").append(players[0].x + 1).append(" ").append(players[0].y + 1).append("\n");
        System.out.print(sb);
        br.close();
    }

}
