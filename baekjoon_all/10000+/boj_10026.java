// Solve 2024-02-20
// Update 2025-09-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Map;
import java.util.TreeMap;

public class boj_10026 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};

    static int countArea(char[][] board, boolean[][] visited, int n, Map<Character, Character> color_map) {
        ArrayDeque<Point> bfsQue = new ArrayDeque<>();
        int areaCount = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (visited[x][y]) continue;

                areaCount++;
                char color = color_map.get(board[x][y]);
                visited[x][y] = true;
                bfsQue.offer(new Point(x, y));

                while (!bfsQue.isEmpty()) {
                    Point cur = bfsQue.poll();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (visited[nx][ny] || color_map.get(board[nx][ny]) != color) continue;

                        visited[nx][ny] = true;
                        bfsQue.offer(new Point(nx, ny));
                    }
                }
            }
        }

        return areaCount;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];

        for (int x = 0; x < n; x++) {
            board[x] = br.readLine().toCharArray();
        }

        boolean[][] visited = new boolean[n][n];
        Map<Character, Character> color_map = new TreeMap<>();
        color_map.put('R', 'R');
        color_map.put('G', 'G');
        color_map.put('B', 'B');
        int areaCount = countArea(board, visited, n, color_map);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                visited[x][y] = false;
            }
        }

        color_map.put('G', 'R');
        int areaCount2 = countArea(board, visited, n, color_map);

        System.out.println(areaCount + " " + areaCount2);
    }

}
