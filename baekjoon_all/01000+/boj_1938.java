// Solve 2024-04-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class boj_1938 {

    static class Point {
        int x, y, direction;

        Point(int x, int y, int direction) {
            this.x = x;
            this.y = y;
            this.direction = direction;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];

        for (int x = 0; x < n; x++) {
            String boardRow = br.readLine();

            for (int y = 0; y < n; y++) {
                board[x][y] = boardRow.charAt(y);
            }
        }

        Point b = new Point(0, 0, 0);
        Point e = new Point(0, 0, 0);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == 'B') {
                    if (x >= 1 && x <= n - 2 && board[x - 1][y] == 'B' && board[x + 1][y] == 'B') {
                        b = new Point(x, y, 0);
                    } else if (y >= 1 && y <= n - 2 && board[x][y - 1] == 'B' && board[x][y + 1] == 'B') {
                        b = new Point(x, y, 1);
                    }
                } else if (board[x][y] == 'E') {
                    if (x >= 1 && x <= n - 2 && board[x - 1][y] == 'E' && board[x + 1][y] == 'E') {
                        e = new Point(x, y, 0);
                    } else if (y >= 1 && y <= n - 2 && board[x][y - 1] == 'E' && board[x][y + 1] == 'E') {
                        e = new Point(x, y, 1);
                    }
                }
            }
        }

        int ans = 0;
        int cnt = 0;
        boolean[][][] visited = new boolean[n][n][2];
        ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
        bfsQue.offer(b);
        visited[b.x][b.y][b.direction] = true;

        while (!bfsQue.isEmpty()) {
            cnt++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                Point cur = bfsQue.poll();

                // 모든 방향에 대해 체크
                if (cur.direction == 0) {
                    boolean left = cur.y >= 1 && board[cur.x - 1][cur.y - 1] != '1' && board[cur.x][cur.y - 1] != '1'
                            && board[cur.x + 1][cur.y - 1] != '1';

                    boolean right = cur.y + 1 < n && board[cur.x - 1][cur.y + 1] != '1'
                            && board[cur.x][cur.y + 1] != '1' && board[cur.x + 1][cur.y + 1] != '1';

                    // 상
                    if (cur.x >= 2 && board[cur.x - 2][cur.y] != '1' && !visited[cur.x - 1][cur.y][0]) {
                        visited[cur.x - 1][cur.y][0] = true;
                        bfsQue.offer(new Point(cur.x - 1, cur.y, 0));

                        if (e.x == cur.x - 1 && e.y == cur.y && e.direction == 0) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 하
                    if (cur.x + 2 < n && board[cur.x + 2][cur.y] != '1' && !visited[cur.x + 1][cur.y][0]) {
                        visited[cur.x + 1][cur.y][0] = true;
                        bfsQue.offer(new Point(cur.x + 1, cur.y, 0));

                        if (e.x == cur.x + 1 && e.y == cur.y && e.direction == 0) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 좌
                    if (left && !visited[cur.x][cur.y - 1][0]) {
                        visited[cur.x][cur.y - 1][0] = true;
                        bfsQue.offer(new Point(cur.x, cur.y - 1, 0));

                        if (e.x == cur.x && e.y == cur.y - 1 && e.direction == 0) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 우
                    if (right && !visited[cur.x][cur.y + 1][0]) {
                        visited[cur.x][cur.y + 1][0] = true;
                        bfsQue.offer(new Point(cur.x, cur.y + 1, 0));

                        if (e.x == cur.x && e.y == cur.y + 1 && e.direction == 0) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 회전
                    if (left && right && !visited[cur.x][cur.y][1]) {
                        visited[cur.x][cur.y][1] = true;
                        bfsQue.offer(new Point(cur.x, cur.y, 1));

                        if (e.x == cur.x && e.y == cur.y && e.direction == 1) {
                            ans = cnt;
                            break;
                        }
                    }
                } else {
                    boolean up = cur.x >= 1 && board[cur.x - 1][cur.y - 1] != '1' && board[cur.x - 1][cur.y] != '1'
                            && board[cur.x - 1][cur.y + 1] != '1';

                    boolean down = cur.x + 1 < n && board[cur.x + 1][cur.y - 1] != '1' && board[cur.x + 1][cur.y] != '1'
                            && board[cur.x + 1][cur.y + 1] != '1';

                    // 좌
                    if (cur.y >= 2 && board[cur.x][cur.y - 2] != '1' && !visited[cur.x][cur.y - 1][1]) {
                        visited[cur.x][cur.y - 1][1] = true;
                        bfsQue.offer(new Point(cur.x, cur.y - 1, 1));

                        if (e.x == cur.x && e.y == cur.y - 1 && e.direction == 1) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 우
                    if (cur.y + 2 < n && board[cur.x][cur.y + 2] != '1' && !visited[cur.x][cur.y + 1][1]) {
                        visited[cur.x][cur.y + 1][1] = true;
                        bfsQue.offer(new Point(cur.x, cur.y + 1, 1));

                        if (e.x == cur.x && e.y == cur.y + 1 && e.direction == 1) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 상
                    if (up && !visited[cur.x - 1][cur.y][1]) {
                        visited[cur.x - 1][cur.y][1] = true;
                        bfsQue.offer(new Point(cur.x - 1, cur.y, 1));

                        if (e.x == cur.x - 1 && e.y == cur.y && e.direction == 1) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 하
                    if (down && !visited[cur.x + 1][cur.y][1]) {
                        visited[cur.x + 1][cur.y][1] = true;
                        bfsQue.offer(new Point(cur.x + 1, cur.y, 1));

                        if (e.x == cur.x + 1 && e.y == cur.y && e.direction == 1) {
                            ans = cnt;
                            break;
                        }
                    }

                    // 회전
                    if (up && down && !visited[cur.x][cur.y][0]) {
                        visited[cur.x][cur.y][0] = true;
                        bfsQue.offer(new Point(cur.x, cur.y, 0));

                        if (e.x == cur.x && e.y == cur.y && e.direction == 0) {
                            ans = cnt;
                            break;
                        }
                    }
                }
                // 모든 방향에 대해 체크 끝
            }

            if (ans != 0) {
                break;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
