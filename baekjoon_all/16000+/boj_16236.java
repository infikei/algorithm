// Solve 2024-01-25
// Update 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class boj_16236 {

    static class Point {
        int x, y;
    
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Shark {
        Point position;
        int size;
        int eatCount;
    
        Shark(int x, int y) {
            position = new Point(x, y);
            size = 2;
            eatCount = 0;
        }
    
        int getX() {
            return position.x;
        }
    
        int getY() {
            return position.y;
        }
    
        void move(int x, int y) {
            position = new Point(x, y);
        }
    
        void eat() {
            if (++eatCount == size) {
                eatCount = 0;
                size++;
            }
        }
    }

    static int[] dx = { -1, 0, 0, 1 };
    static int[] dy = { 0, -1, 1, 0 };
    static int n;
    static int[][] board;
    static Shark babyShark;
    static int curTime = 0;
    static Comparator<Point> cp = new Comparator<>() {

        @Override
        public int compare(Point p1, Point p2) {
            if (p1.x != p2.x) {
                return p1.x - p2.x;
            }

            return p1.y - p2.y;
        }

    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        babyShark = new Shark(0, 0);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());

                if (board[i][j] == 9) {
                    babyShark = new Shark(i, j);
                    board[i][j] = 0;
                }
            }
        }

        while (movePosition()) {}

        System.out.println(curTime);
        br.close();
    }

    static boolean movePosition() {
        List<Point> positions = new ArrayList<>();
        boolean[][] visited = new boolean[n][n];
        int dist = 0;
        positions.add(new Point(babyShark.getX(), babyShark.getY()));
        visited[babyShark.getX()][babyShark.getY()] = true;

        while (!positions.isEmpty()) {
            ++dist;
            List<Point> canMove = new ArrayList<>();
            List<Point> canEat = new ArrayList<>();

            for (Point cur : positions) {
                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (!isInBoard(nx, ny) || visited[nx][ny]) continue;

                    visited[nx][ny] = true;

                    if (board[nx][ny] == 0 || board[nx][ny] == babyShark.size) {
                        canMove.add(new Point(nx, ny));
                    } else if (board[nx][ny] < babyShark.size) {
                        canEat.add(new Point(nx, ny));
                    }
                }
            }

            if (canEat.isEmpty()) {
                positions = canMove;
            } else {
                canEat.sort(cp);
                Point next = canEat.get(0);
                curTime += dist;
                board[next.x][next.y] = 0;
                babyShark.move(next.x, next.y);
                babyShark.eat();
                return true;
            }
        }

        return false;
    }

    static boolean isInBoard(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < n) {
            return true;
        }

        return false;
    }

}
