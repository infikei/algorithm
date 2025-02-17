// Solve 2025-02-17

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_13460 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    static class Balls {
        int rx, ry, bx, by;

        Balls(int rx, int ry, int bx, int by) {
            this.rx = rx;
            this.ry = ry;
            this.bx = bx;
            this.by = by;
        }

        Balls move(int redMoved, int blueMoved, int d) {
            int rx = this.rx + dx[d] * redMoved;
            int ry = this.ry + dy[d] * redMoved;
            int bx = this.bx + dx[d] * blueMoved;
            int by = this.by + dy[d] * blueMoved;

            return new Balls(rx, ry, bx, by);
        }
    }

    static int move(int x, int y, int d, char[][] board) {
        int moved = 1;
        int nx = x + dx[d];
        int ny = y + dy[d];

        while (board[nx][ny] == '.') {
            moved++;
            nx += dx[d];
            ny += dy[d];
        }

        if (board[nx][ny] == 'O') {
            return moved;
        }

        return moved - 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] board = new char[n][m];
        Balls balls = new Balls(0, 0, 0, 0);

        for (int x = 0; x < n; x++) {
            board[x] = br.readLine().toCharArray();

            for (int y = 0; y < m; y++) {
                if (board[x][y] == 'R') {
                    balls.rx = x;
                    balls.ry = y;
                    board[x][y] = '.';
                } else if (board[x][y] == 'B') {
                    balls.bx = x;
                    balls.by = y;
                    board[x][y] = '.';
                }
            }
        }

        boolean[][][][] visited = new boolean[n][m][n][m];
        ArrayDeque<Balls> bfsQue = new ArrayDeque<Balls>();
        bfsQue.add(balls);
        visited[balls.rx][balls.ry][balls.bx][balls.by] = true;
        int ans = -1;

        for (int depth = 1; depth <= 10; depth++) {
            int bfsIter = bfsQue.size();

            while (bfsIter-- > 0) {
                Balls cur = bfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int redMoved = move(cur.rx, cur.ry, d, board);
                    int blueMoved = move(cur.bx, cur.by, d, board);
                    Balls nxt = cur.move(redMoved, blueMoved, d);

                    // 파란 구슬이 구멍에 들어가면 더 이상 탐색하지 않는다.
                    if (board[nxt.bx][nxt.by] == 'O') {
                        continue;
                    }

                    // 빨간 구슬과 파란 구슬은 같은 칸에 위치할 수 없으므로 더 먼 거리를 이동한 구슬을 한 칸 뒤로 이동시킨다.
                    if (nxt.rx == nxt.bx && nxt.ry == nxt.by) {
                        if (redMoved > blueMoved) {
                            nxt.rx -= dx[d];
                            nxt.ry -= dy[d];
                        }
                        else {
                            nxt.bx -= dx[d];
                            nxt.by -= dy[d];
                        }
                    }

                    // 빨간 구슬이 구멍에 들어가면 그때의 횟수를 답에 저장하고 탐색을 종료한다.
                    if (board[nxt.rx][nxt.ry] == 'O') {
                        ans = depth;
                        break;
                    }

                    // 이미 탐색이 진행된 경우라면 중복해서 탐색하지 않는다.
                    if (visited[nxt.rx][nxt.ry][nxt.bx][nxt.by]) {
                        continue;
                    }

                    bfsQue.add(nxt);
                    visited[nxt.rx][nxt.ry][nxt.bx][nxt.by] = true;
                }

                if (ans != -1) break;
            }

            if (ans != -1) break;
        }

        System.out.println(ans);
    }

}
