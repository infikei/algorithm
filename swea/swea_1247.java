// Solve 2024-02-15

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1247 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        int getDistFrom(Point p) {
            return Math.abs(this.x - p.x) + Math.abs(this.y - p.y);
        }
    }

    static int n;
    static Point[] points;
    static int minSumDist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            n = Integer.parseInt(br.readLine());
            points = new Point[n + 2];
            minSumDist = Integer.MAX_VALUE;
            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < n + 2; i++) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                points[i] = new Point(x, y);
            }

            dfs(2, 0, 0, 0);
            sb.append("#").append(ti).append(" ").append(minSumDist).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static void dfs(int depth, int prev, int selected, int sumDist) {
        if (sumDist >= minSumDist) return;

        if (depth == n + 2) {
            sumDist += points[1].getDistFrom(points[prev]);

            if (sumDist < minSumDist) {
                minSumDist = sumDist;
            }

            return;
        }

        for (int i = 2; i < n + 2; i++) {
            if ((selected & 1 << i) != 0) continue;

            dfs(depth + 1, i, selected | 1 << i, sumDist + points[i].getDistFrom(points[prev]));
        }
    }

}
