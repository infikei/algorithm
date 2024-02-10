// Solve 2024-02-07
// Update 2024-02-10

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17470 {

    static BufferedReader br;
    static StringTokenizer st;
    static int n, m, r, n2, m2;
    static int[][][][] board;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        n2 = n / 2;
        m2 = m / 2;

        inputBoardByPart();

        st = new StringTokenizer(br.readLine(), " ");
        boolean verticalReverse = false;
        boolean horizontalReverse = false;
        int rotateCnt = 0;

        while (r-- > 0) {
            String cmd = st.nextToken();
            int[][] tmp;

            if (cmd.equals("1")) {
                // 상하 반전
                if ((rotateCnt & 1) == 0) {
                    verticalReverse = !verticalReverse;
                } else {
                    horizontalReverse = !horizontalReverse;
                }

                tmp = board[0][0];
                board[0][0] = board[1][0];
                board[1][0] = tmp;

                tmp = board[0][1];
                board[0][1] = board[1][1];
                board[1][1] = tmp;
            } else if (cmd.equals("2")) {
                // 좌우 반전
                if ((rotateCnt & 1) == 0) {
                    horizontalReverse = !horizontalReverse;
                } else {
                    verticalReverse = !verticalReverse;
                }

                tmp = board[0][0];
                board[0][0] = board[0][1];
                board[0][1] = tmp;

                tmp = board[1][0];
                board[1][0] = board[1][1];
                board[1][1] = tmp;
            } else if (cmd.equals("3")) {
                // 오른쪽으로 90도 회전
                if (++rotateCnt == 4) {
                    rotateCnt = 0;
                }

                tmp = board[0][0];
                board[0][0] = board[1][0];
                board[1][0] = board[1][1];
                board[1][1] = board[0][1];
                board[0][1] = tmp;
            } else if (cmd.equals("4")) {
                // 왼쪽으로 90도 회전
                if (--rotateCnt == -1) {
                    rotateCnt = 3;
                }

                tmp = board[0][0];
                board[0][0] = board[0][1];
                board[0][1] = board[1][1];
                board[1][1] = board[1][0];
                board[1][0] = tmp;
            } else if (cmd.equals("5")) {
                // 사분면의 위치를 시계 방향으로 이동
                tmp = board[0][0];
                board[0][0] = board[1][0];
                board[1][0] = board[1][1];
                board[1][1] = board[0][1];
                board[0][1] = tmp;
            } else {
                // 사분면의 위치를 반시계 방향으로 이동
                tmp = board[0][0];
                board[0][0] = board[0][1];
                board[0][1] = board[1][1];
                board[1][1] = board[1][0];
                board[1][0] = tmp;
            }
        }

        // 사분면의 위치 이동은 이미 위에서 모두 처리했다.
        // 이제 사분면의 위치 이동 없이, 각각의 사분면 내부에서 상하 반전, 좌우 반전, 회전을 처리한다.

        if (verticalReverse) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    // 각각의 사분면 내부에서 상하 반전
                    reverse(board[i][j], n2);
                }
            }
        }

        if (horizontalReverse) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    // 각각의 사분면 내부에서 좌우 반전
                    for (int x = 0; x < n2; x++) {
                        reverse(board[i][j][x], m2);
                    }
                }
            }
        }

        rotateBoardByPart(rotateCnt); // 각각의 사분면 내부에서 회전
        printBoard(); // 배열 출력
        br.close();
    }

    /** 1차원 배열 reverse */
    static void reverse(int[] arr, int size) {
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    /** 2차원 배열 reverse */
    static void reverse(int[][] arr, int size) {
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            int[] tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    /** 각각의 사분면 내부에서 회전 */
    static void rotateBoardByPart(int rotateCnt) {
        if (rotateCnt == 0) return;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int[][] newArr = new int[50][50];

                if (rotateCnt == 1) {
                    for (int x = 0; x < n2; x++) {
                        for (int y = 0; y < m2; y++) {
                            newArr[y][n2 - 1 - x] = board[i][j][x][y];
                        }
                    }
                } else if (rotateCnt == 2) {
                    for (int x = 0; x < n2; x++) {
                        for (int y = 0; y < m2; y++) {
                            newArr[n2 - 1 - x][m2 - 1 - y] = board[i][j][x][y];
                        }
                    }
                } else if (rotateCnt == 3) {
                    for (int x = 0; x < n2; x++) {
                        for (int y = 0; y < m2; y++) {
                            newArr[m2 - 1 - y][x] = board[i][j][x][y];
                        }
                    }
                }

                board[i][j] = newArr;
            }
        }

        if ((rotateCnt & 1) == 1) {
            int tmp = n;
            n = m;
            m = tmp;

            tmp = n2;
            n2 = m2;
            m2 = tmp;
        }
    }

    /** 2차원 배열을 입력받고 각각의 사분면으로 나눠서 4차원 배열로 저장 */
    static void inputBoardByPart() throws IOException {
        board = new int[2][2][50][50];

        for (int x = 0; x < n2; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m2; y++) {
                board[0][0][x][y] = Integer.parseInt(st.nextToken());
            }

            for (int y = 0; y < m2; y++) {
                board[0][1][x][y] = Integer.parseInt(st.nextToken());
            }
        }

        for (int x = 0; x < n2; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < m2; y++) {
                board[1][0][x][y] = Integer.parseInt(st.nextToken());
            }

            for (int y = 0; y < m2; y++) {
                board[1][1][x][y] = Integer.parseInt(st.nextToken());
            }
        }
    }

    /** 배열을 2차원으로 출력 */
    static void printBoard() {
        StringBuilder sb = new StringBuilder();

        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < m2; y++) {
                sb.append(board[0][0][x][y]).append(" ");
            }

            for (int y = 0; y < m2; y++) {
                sb.append(board[0][1][x][y]).append(" ");
            }

            sb.append("\n");
        }

        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < m2; y++) {
                sb.append(board[1][0][x][y]).append(" ");
            }

            for (int y = 0; y < m2; y++) {
                sb.append(board[1][1][x][y]).append(" ");
            }

            sb.append("\n");
        }

        System.out.print(sb);
    }

}
