// Solve 2024-01-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class boj_3190 {
    private static int[] dx = { 0, 1, 0, -1 };
    private static int[] dy = { 1, 0, -1, 0 };
    private static int[][] board;
    private static int n, k, l;
    private static int curTime = 0;
    private static int curDirection = 0;
    private static boolean gameState = true;
    private static Deque<int[]> snake = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        board = new int[n][n];

        while (k-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int appleX = Integer.parseInt(st.nextToken()) - 1;
            int appleY = Integer.parseInt(st.nextToken()) - 1;
            board[appleX][appleY] = 2;
        }

        l = Integer.parseInt(br.readLine());
        snake.offerLast(new int[] { 0, 0 });
        board[0][0] = 1;

        while (l-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int timeToChange = Integer.parseInt(st.nextToken());
            char directionToChange = st.nextToken().charAt(0);

            while (gameState && curTime < timeToChange) {
                curTime++;
                moveSnake();
            }

            if (!gameState) break;

            changeDirection(directionToChange);
        }

        while (gameState) {
            curTime++;
            moveSnake();
        }

        System.out.println(curTime);
        br.close();
    }

    private static void changeDirection(char directionToChange) {
        if (directionToChange == 'L') {
            if (--curDirection == -1) {
                curDirection = 3;
            }
        } else {
            if (++curDirection == 4) {
                curDirection = 0;
            }
        }
    }

    private static void moveSnake() {
        int headX = snake.peekLast()[0] + dx[curDirection];
        int headY = snake.peekLast()[1] + dy[curDirection];

        if (headX < 0 || headX >= n || headY < 0 || headY >= n) {
            gameState = false;
            return;
        }

        if (board[headX][headY] == 1) {
            gameState = false;
            return;
        }

        if (board[headX][headY] == 0) {
            int tailX = snake.peekFirst()[0];
            int tailY = snake.peekFirst()[1];
            snake.pollFirst();
            board[tailX][tailY] = 0;
        }

        board[headX][headY] = 1;
        snake.offerLast(new int[] { headX, headY });
    }
}
