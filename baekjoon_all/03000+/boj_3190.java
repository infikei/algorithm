// Solve 2024-01-22
// Update 2024-01-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_3190 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Snake {
        Point head;
        Queue<Point> body;
        int direction;

        Snake() {
            head = new Point(0, 0);
            body = new LinkedList<>();
            body.add(new Point(0, 0));
            direction = 0;
        }

        void changeDirection(char directionToChange) {
            if (directionToChange == 'L') {
                if (--direction == -1) {
                    direction = 3;
                }
            } else {
                if (++direction == 4) {
                    direction = 0;
                }
            }
        }

        void move() {
            Point nextHead = new Point(head.x + dx[direction], head.y + dy[direction]);
    
            if (!isInBoard(nextHead.x, nextHead.y)) {
                gameState = false;
                return;
            }
    
            if (board[nextHead.x][nextHead.y] == 2) {
                gameState = false;
                return;
            }
    
            if (board[nextHead.x][nextHead.y] == 0) {
                Point tail = body.poll();
                board[tail.x][tail.y] = 0;
            }
    
            board[nextHead.x][nextHead.y] = 2;
            body.offer(new Point(nextHead.x, nextHead.y));
            head = nextHead;
        }
    }

    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { 1, 0, -1, 0 };
    static int n, k, l;
    static int[][] board;
    static Snake snake;
    static int curTime = 0;
    static boolean gameState = true;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        board = new int[n][n];
        snake = new Snake();

        while (k-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int appleX = Integer.parseInt(st.nextToken()) - 1;
            int appleY = Integer.parseInt(st.nextToken()) - 1;
            board[appleX][appleY] = 4;
        }

        l = Integer.parseInt(br.readLine());
        board[0][0] = 2;

        while (l-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int timeToChange = Integer.parseInt(st.nextToken());
            char directionToChange = st.nextToken().charAt(0);

            while (gameState && curTime < timeToChange) {
                curTime++;
                snake.move();
            }

            if (!gameState) break;

            snake.changeDirection(directionToChange);
        }

        while (gameState) {
            curTime++;
            snake.move();
        }

        System.out.println(curTime);
        br.close();
    }

    static boolean isInBoard(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return false;
        }

        return true;
    }

}
