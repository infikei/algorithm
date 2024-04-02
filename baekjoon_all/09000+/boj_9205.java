// Solve 2024-04-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_9205 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        int getDist(Point p) {
            return Math.abs(this.x - p.x) + Math.abs(this.y - p.y);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            Point[] points = new Point[n + 2];

            for (int u = 0; u < n + 2; u++) {
                st = new StringTokenizer(br.readLine(), " ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                points[u] = new Point(x, y);
            }

            ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
            bfsQue.offer(0);
            boolean[] visited = new boolean[n + 2];
            visited[0] = true;

            while (!bfsQue.isEmpty()) {
                int cur = bfsQue.poll();

                for (int u = 1; u < n + 2; u++) {
                    if (!visited[u] && points[cur].getDist(points[u]) <= 1000) {
                        bfsQue.offer(u);
                        visited[u] = true;
                    }
                }
            }

            sb.append(visited[n + 1] ? "happy\n" : "sad\n");
        }

        System.out.print(sb);
        br.close();
    }

}
