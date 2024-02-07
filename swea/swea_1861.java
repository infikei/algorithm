// Solve 2024-02-07

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1861 {

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            int[][] board = new int[n][n];
            boolean[][] visited = new boolean[n][n];

            for (int x = 0; x < n; x++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int y = 0; y < n; y++) {
                    board[x][y] = Integer.parseInt(st.nextToken());
                }
            }

            int numOfMaxCnt = 0;
            int maxCnt = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j]) continue;

                    visited[i][j] = true;
                    int curCnt = 1;
                    int x = i;
                    int y = j;

                    while (true) {
                        boolean flag = false;

                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == board[x][y] + 1) {
                                flag = true;
                                visited[nx][ny] = true;
                                curCnt++;
                                x = nx;
                                y = ny;
                                break;
                            }
                        }

                        if (!flag) break;
                    }

                    if (maxCnt < curCnt) {
                        maxCnt = curCnt;
                        numOfMaxCnt = board[i][j];
                    } else if (maxCnt == curCnt && numOfMaxCnt > board[i][j]) {
                        numOfMaxCnt = board[i][j];
                    }
                }
            }

            sb.append("#").append(ti).append(" ").append(numOfMaxCnt).append(" ").append(maxCnt)
                    .append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
