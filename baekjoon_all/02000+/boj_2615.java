// Solve 2024-01-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2615 {

    static boolean isInBoard(int x, int y) {
        return x >= 1 && x <= 19 && y >= 1 && y <= 19;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int[][] board = new int[20][20];

        for (int i = 1; i <= 19; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 1; j <= 19; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[] dx = { -1, 0, 1, 1 };
        int[] dy = { 1, 1, 1, 0 };
        int ans = 0;
        int ansX = 0;
        int ansY = 0;

        // 모든 위치에 대해서 조사한다.
        forDepth1: for (int x = 1; x <= 19; x++) {
            for (int y = 1; y <= 19; y++) {
                // 현재 위치에 알이 놓이지 않은 경우, 탐색하지 않고 skip한다.
                if (board[x][y] == 0) continue;

                // 각 위치마다 4가지 방향에 대해서 탐색한다. (우상, 우, 우하, 하)
                forDepth3: for (int d = 0; d < 4; d++) {
                    // 선택된 방향으로 4번째 다음 위치가 보드 밖인 경우 탐색하지 않고 skip한다.
                    if (!isInBoard(x + dx[d] * 4, y + dy[d] * 4)) continue;

                    int nx = x;
                    int ny = y;

                    // 현재 위치에서 선택된 방향으로 4번째 다음 위치까지 같은 알이 놓여있는지 조사한다.
                    for (int k = 1; k <= 4; k++) {
                        nx += dx[d];
                        ny += dy[d];

                        if (board[x][y] != board[nx][ny]) {
                            continue forDepth3;
                        }
                    }

                    // 현재 위치에서 선택된 방향으로 5번째 다음 위치에 같은 알이 놓여있는 경우, 6목이므로 skip한다.
                    nx = x + dx[d] * 5;
                    ny = y + dy[d] * 5;

                    if (isInBoard(nx, ny) && board[x][y] == board[nx][ny]) {
                        continue forDepth3;
                    }

                    // 현재 위치에서 선택된 방향의 반대 방향으로 같은 알이 놓여있는 경우, 이 또한 6목이므로 skip한다.
                    nx = x - dx[d];
                    ny = y - dy[d];

                    if (isInBoard(nx, ny) && board[x][y] == board[nx][ny]) {
                        continue forDepth3;
                    }

                    // 위의 모든 case에 해당하지 않는 경우, 완전한 5목이므로 답과 위치를 저장하고 모든 반복문을 탈출한다.
                    ans = board[x][y];
                    ansX = x;
                    ansY = y;
                    break forDepth1;
                }
            }
        }

        System.out.println(ans);

        if (ans != 0) {
            System.out.println(ansX + " " + ansY);
        }
    }

}
