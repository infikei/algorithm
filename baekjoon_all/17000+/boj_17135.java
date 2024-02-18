// Solve 2024-02-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_17135 {

    static int[] dx = { 0, -1, 0 };
    static int[] dy = { -1, 0, 1 };
    static int n, m, d;
    static int[][] board;
    static boolean[][] killed;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        board = new int[n][m];
        killed = new boolean[n][m];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int maxKillCount = 0;

        for (int ay = 0; ay < m; ay++) {
            for (int by = ay + 1; by < m; by++) {
                for (int cy = by + 1; cy < m; cy++) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            killed[i][j] = false;
                        }
                    }

                    int x = n;
                    int killCount = 0;

                    while (--x >= 0) {
                        int[] targetA = getNextTarget(x, ay);
                        int[] targetB = getNextTarget(x, by);
                        int[] targetC = getNextTarget(x, cy);

                        if (targetA != null) {
                            killed[targetA[0]][targetA[1]] = true;
                            killCount++;
                        }

                        if (targetB != null && !killed[targetB[0]][targetB[1]]) {
                            killed[targetB[0]][targetB[1]] = true;
                            killCount++;
                        }

                        if (targetC != null && !killed[targetC[0]][targetC[1]]) {
                            killed[targetC[0]][targetC[1]] = true;
                            killCount++;
                        }
                    }

                    if (killCount > maxKillCount) {
                        maxKillCount = killCount;
                    }
                }
            }
        }

        System.out.println(maxKillCount);
        br.close();
    }

    static int[] getNextTarget(int x, int y) {
        if (board[x][y] == 1 && !killed[x][y]) return new int[] { x, y };

        Queue<int[]> bfsQue = new ArrayDeque<int[]>();
        bfsQue.offer(new int[] { x, y, 1 });

        while (!bfsQue.isEmpty()) {
            int[] curPos = bfsQue.poll();

            for (int direction = 0; direction < 3; direction++) {
                int nx = curPos[0] + dx[direction];
                int ny = curPos[1] + dy[direction];
                int nd = curPos[2] + 1;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && nd <= d) {
                    if (board[nx][ny] == 1 && !killed[nx][ny]) {
                        return new int[] { nx, ny };
                    } else {
                        bfsQue.offer(new int[] { nx, ny, nd });
                    }
                }
            }
        }

        return null;
    }

}
