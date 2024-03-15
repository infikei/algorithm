// Solve 2024-03-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17143 {

    static int r, c;

    static class Shark {
        int speed, direction, size;

        Shark(int speed, int direction, int size) {
            this.speed = speed;
            this.direction = direction;
            this.size = size;
        }

        int[] move(int x, int y) {
            if (speed > 0) {
                if (direction <= 2) {
                    if (direction == 1) {
                        x = (r - 1) * 2 - x;
                        direction = 2;
                    }

                    x = (x + speed - 1) % ((r - 1) * 2) + 1;

                    if (x >= r) {
                        x = (r - 1) * 2 - x;
                        direction = 1;
                    }
                } else {
                    if (direction == 4) {
                        y = (c - 1) * 2 - y;
                        direction = 3;
                    }

                    y = (y + speed - 1) % ((c - 1) * 2) + 1;

                    if (y >= c) {
                        y = (c - 1) * 2 - y;
                        direction = 4;
                    }
                }
            }

            return new int[] { x, y };
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Shark[][] board = new Shark[c][r];
        Shark[][] oldBoard = new Shark[c][r];
        Shark[][] tmpBoard = null;

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            int speed = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());

            board[y][x] = new Shark(speed, direction, size);
        }

        int sharkSum = 0;

        for (int py = 0; py < c; py++) {
            tmpBoard = oldBoard;
            oldBoard = board;
            board = tmpBoard;
            tmpBoard = null;

            for (int px = 0; px < r; px++) {
                if (oldBoard[py][px] != null) {
                    sharkSum += oldBoard[py][px].size;
                    oldBoard[py][px] = null;
                    break;
                }
            }

            for (int y = 0; y < c; y++) {
                for (int x = 0; x < r; x++) {
                    if (oldBoard[y][x] != null) {
                        int[] nextPos = oldBoard[y][x].move(x, y);
                        int nx = nextPos[0];
                        int ny = nextPos[1];
    
                        if (board[ny][nx] != null) {
                            if (oldBoard[y][x].size > board[ny][nx].size) {
                                board[ny][nx] = null;
                                board[ny][nx] = oldBoard[y][x];
                                oldBoard[y][x] = null;
                            } else {
                                oldBoard[y][x] = null;
                            }
                        } else {
                            board[ny][nx] = oldBoard[y][x];
                            oldBoard[y][x] = null;
                        }
                    }
                }
            }
        }

        System.out.println(sharkSum);
        br.close();
    }

}
