// Solve 2024-03-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_1194 {

    static class State {
        int x, y, dist, keys;

        public State(int x, int y, int dist, int keys) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.keys = keys;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        boolean[][][] visited = new boolean[n][m][64];
        ArrayDeque<State> bfsQue = new ArrayDeque<State>();

        for (int x = 0; x < n; x++) {
            String s = br.readLine();

            for (int y = 0; y < m; y++) {
                board[x][y] = s.charAt(y);

                if (board[x][y] == '0') {
                    board[x][y] = '.';
                    bfsQue.offer(new State(x, y, 0, 0));
                    visited[x][y][0] = true;
                }
            }
        }

        int ans = -1;

        while (!bfsQue.isEmpty()) {
            State cur = bfsQue.poll();
            char curBoard = board[cur.x][cur.y];

            if (curBoard >= 'a' && curBoard <= 'f') {
                cur.keys |= 1 << (curBoard - 'a');
            }

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][cur.keys]) {
                    continue;
                }

                char nBoard = board[nx][ny];

                if (nBoard == '1') {
                    ans = cur.dist + 1;
                    break;
                } else if (nBoard >= 'A' && nBoard <= 'F') {
                    if ((cur.keys & (1 << (nBoard - 'A'))) != 0) {
                        bfsQue.offer(new State(nx, ny, cur.dist + 1, cur.keys));
                        visited[nx][ny][cur.keys] = true;
                    }
                } else if (nBoard != '#') {
                    bfsQue.offer(new State(nx, ny, cur.dist + 1, cur.keys));
                    visited[nx][ny][cur.keys] = true;
                }
            }

            if (ans != -1) {
                break;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
