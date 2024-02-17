// Solve 2024-02-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_4963 {

    static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine(), " ");
            int w = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());

            if (w == 0 && h == 0) break;

            int[][] board = new int[h][w];

            for (int x = 0; x < h; x++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int y = 0; y < w; y++) {
                    board[x][y] = st.nextToken().charAt(0) - '0';
                }
            }

            boolean[][] visited = new boolean[h][w];
            int areaCount = 0;

            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (visited[x][y] || board[x][y] == 0) continue;

                    areaCount++;
                    Queue<int[]> bfsQue = new ArrayDeque<int[]>();
                    bfsQue.offer(new int[] { x, y });
                    visited[x][y] = true;

                    while (!bfsQue.isEmpty()) {
                        int[] cur = bfsQue.poll();

                        for (int d = 0; d < 8; d++) {
                            int nx = cur[0] + dx[d];
                            int ny = cur[1] + dy[d];

                            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && board[nx][ny] == 1) {
                                bfsQue.offer(new int[] { nx, ny });
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }

            sb.append(areaCount).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
