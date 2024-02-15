// Solve 2024-02-15

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1873 {

    static class Tank {
        int x, y, d;

        Tank(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }

        void move(int d) {
            this.d = d;
            int nx = this.x + dx[d];
            int ny = this.y + dy[d];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] == '.') {
                this.x = nx;
                this.y = ny;
            }
        }

        void shoot() {
            int nx = x + dx[d];
            int ny = y + dy[d];

            while (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (board[nx][ny] == '*') {
                    board[nx][ny] = '.';
                    break;
                } else if (board[nx][ny] == '#') {
                    break;
                }

                nx += dx[d];
                ny += dy[d];
            }
        }
    }

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static int h, w;
    static char[][] board;
    static Tank tank;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            // board의 크기인 h와 w를 입력받는다.
            st = new StringTokenizer(br.readLine(), " ");
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            // board를 입력받는다.
            board = new char[h][w];
            boolean flagFound = false;

            for (int x = 0; x < h; x++) {
                board[x] = br.readLine().toCharArray();

                if (flagFound) continue;

                // 탱크의 위치와 방향을 tank 객체에 저장하고, board에서는 그 칸을 평지로 치환한다.
                // 만약 탱크를 이미 찾은 경우에는 탐색을 더 이상 진행하지 않는다.
                for (int y = 0; y < w; y++) {
                    if (board[x][y] == '^') {
                        tank = new Tank(x, y, 0);
                        board[x][y] = '.';
                        flagFound = true;
                        break;
                    } else if (board[x][y] == 'v') {
                        tank = new Tank(x, y, 1);
                        board[x][y] = '.';
                        flagFound = true;
                        break;
                    } else if (board[x][y] == '<') {
                        tank = new Tank(x, y, 2);
                        board[x][y] = '.';
                        flagFound = true;
                        break;
                    } else if (board[x][y] == '>') {
                        tank = new Tank(x, y, 3);
                        board[x][y] = '.';
                        flagFound = true;
                        break;
                    }
                }
            }

            // n과 cmds를 입력받고, 각 cmd에 따라 동작을 처리한다.
            int n = Integer.parseInt(br.readLine());
            String cmds = br.readLine();

            for (int i = 0; i < n; i++) {
                char cmd = cmds.charAt(i);

                if (cmd == 'U') {
                    tank.move(0);
                } else if (cmd == 'D') {
                    tank.move(1);
                } else if (cmd == 'L') {
                    tank.move(2);
                } else if (cmd == 'R') {
                    tank.move(3);
                } else if (cmd == 'S') {
                    tank.shoot();
                }
            }

            // 보드를 출력하기 전에 보드의 위치를 다시 전차를 나타내는 문자로 치환한다.
            if (tank.d == 0) {
                board[tank.x][tank.y] = '^';
            } else if (tank.d == 1) {
                board[tank.x][tank.y] = 'v';
            } else if (tank.d == 2) {
                board[tank.x][tank.y] = '<';
            } else {
                board[tank.x][tank.y] = '>';
            }

            // 테스트 케이스 번호와 보드를 출력한다.
            sb.append("#").append(ti).append(" ");

            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    sb.append(board[x][y]);
                }

                sb.append("\n");
            }
        }

        System.out.print(sb);
        br.close();
    }

}
