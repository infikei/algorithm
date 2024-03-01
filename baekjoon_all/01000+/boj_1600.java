// Solve 2024-02-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_1600 {

    static int[] dx = { 0, 0, -1, 1, -2, -2, -1, -1, 1, 1, 2, 2 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -2, 2, -2, 2, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int[][] board = new int[h][w];

        for (int x = 0; x < h; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < w; y++) {
                board[x][y] = st.nextToken().charAt(0) - '0';
            }
        }

        boolean[][][] visited = new boolean[k + 1][h][w];
        ArrayDeque<int[]> bfsQue = new ArrayDeque<int[]>();
        visited[0][0][0] = true;
        bfsQue.offer(new int[] { 0, 0, 0 });
        int ans = -1;
        int curDist = 0;

        while (ans == -1 && !bfsQue.isEmpty()) {
            int curIter = bfsQue.size();

            while (curIter-- > 0) {
                int[] curPos = bfsQue.poll();
                int curJump = curPos[0];
                int curX = curPos[1];
                int curY = curPos[2];

                if (curX == h - 1 && curY == w - 1) {
                    ans = curDist;
                    break;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = curX + dx[d];
                    int ny = curY + dy[d];

                    if (curJump <= k && nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] == 0 && !visited[curJump][nx][ny]) {
                        visited[curJump][nx][ny] = true;
                        bfsQue.offer(new int[] { curJump, nx, ny });
                    }
                }

                for (int d = 4; d < 12; d++) {
                    int nx = curX + dx[d];
                    int ny = curY + dy[d];

                    if (curJump < k && nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] == 0 && !visited[curJump + 1][nx][ny]) {
                        visited[curJump + 1][nx][ny] = true;
                        bfsQue.offer(new int[] { curJump + 1, nx, ny });
                    }
                }
            }

            curDist++;
        }

        System.out.println(ans);
        br.close();
    }

}
