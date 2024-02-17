// Solve 2024-02-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_7576 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int notRipe = 0;
        Queue<int[]> bfsQue = new ArrayDeque<int[]>();

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());

                if (board[x][y] == 0) {
                    notRipe++;
                } else if (board[x][y] == 1) {
                    bfsQue.offer(new int[] { x, y });
                }
            }
        }

        int curDay = 0;

        while (notRipe > 0 && !bfsQue.isEmpty()) {
            curDay++;
            int curIter = bfsQue.size();

            while (curIter-- > 0) {
                int[] curPos = bfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = curPos[0] + dx[d];
                    int ny = curPos[1] + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0) {
                        board[nx][ny] = 1;
                        bfsQue.offer(new int[] { nx, ny });
                        notRipe--;
                    }
                }
            }
        }

        System.out.println(notRipe > 0 ? -1 : curDay);
        br.close();
    }

}
