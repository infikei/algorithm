// Solve 2024-02-09

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_16234 {

    static int[] dx = { -1, 0, 0, 1 };
    static int[] dy = { 0, -1, 1, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int left = Integer.parseInt(st.nextToken());
        int right = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];
        int[][] newBoard = new int[n][n];
        int[][] tmpBoard;

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;

        while (true) {
            boolean[][] visited = new boolean[n][n];
            boolean breakFlag = true;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (visited[x][y]) continue;

                    visited[x][y] = true;
                    ArrayList<int[]> positions = new ArrayList<int[]>();
                    int bfsNextIdx = 0;
                    positions.add(new int[] { x, y });
                    int blockCnt = 1;
                    int blockSum = board[x][y];

                    while (bfsNextIdx < positions.size()) {
                        int[] cur = positions.get(bfsNextIdx++);

                        for (int d = 0; d < 4; d++) {
                            int nx = cur[0] + dx[d];
                            int ny = cur[1] + dy[d];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;

                            int diff = Math.abs(board[cur[0]][cur[1]] - board[nx][ny]);

                            if (diff >= left && diff <= right) {
                                visited[nx][ny] = true;
                                positions.add(new int[] { nx, ny });
                                blockCnt++;
                                blockSum += board[nx][ny];
                            }
                        }
                    }

                    int newBlockNum = blockSum / blockCnt;

                    for (int[] pos : positions) {
                        newBoard[pos[0]][pos[1]] = newBlockNum;
                    }

                    if (blockCnt >= 2) {
                        breakFlag = false;
                    }
                }
            }

            tmpBoard = board;
            board = newBoard;
            newBoard = tmpBoard;
            tmpBoard = null;

            if (breakFlag) break;

            ans++;
        }

        System.out.println(ans);
        br.close();
    }

}
