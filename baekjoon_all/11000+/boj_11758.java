// Solve 2024-02-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_11758 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        Point subtract(Point p) {
            return new Point(this.x - p.x, this.y - p.y);
        }

        int getCross(Point p) {
            return this.x * p.y - p.x * this.y;
        }

        int getCcw(Point p1, Point p2) {
            return p1.subtract(this).getCross(p2.subtract(this));
        }

        int getCcwSign(Point p1, Point p2) {
            int ccw = getCcw(p1, p2);

            if (ccw > 0) return 1;
            if (ccw < 0) return -1;
            return 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Point[] points = new Point[3];

        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            points[i] = new Point(x, y);
        }

        System.out.println(points[0].getCcwSign(points[1], points[2]));

        br.close();
    }

}
