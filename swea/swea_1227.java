// Solve 2024-02-16

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class swea_1227 {

    static int[] dx = { -1, 0, 0, 1 };
    static int[] dy = { 0, -1, 1, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int ti = 1; ti <= 10; ti++) {
            int tc = Integer.parseInt(br.readLine());
            int[][] board = new int[100][100];
            int sx = 0, sy = 0;

            for (int x = 0; x < 100; x++) {
                String row = br.readLine();

                for (int y = 0; y < 100; y++) {
                    board[x][y] = row.charAt(y) - '0';

                    if (board[x][y] == 2) {
                        sx = x;
                        sy = y;
                    }
                }
            }

            Queue<int[]> bfsQue = new ArrayDeque<int[]>();
            boolean[][] visited = new boolean[100][100];
            bfsQue.offer(new int[] { sx, sy });
            visited[sx][sy] = true;
            boolean foundRoute = false;

            while (!bfsQue.isEmpty()) {
                int[] cur = bfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = cur[0] + dx[d];
                    int ny = cur[1] + dy[d];

                    if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100 || visited[nx][ny]) continue;

                    if (board[nx][ny] == 3) {
                        foundRoute = true;
                        break;
                    } else if (board[nx][ny] == 0) {
                        bfsQue.offer(new int[] { nx, ny });
                        visited[nx][ny] = true;
                    }
                }

                if (foundRoute) break;
            }

            sb.append("#").append(tc).append(" ").append(foundRoute ? 1 : 0).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
