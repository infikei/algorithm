// Solve 2024-02-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2166 {

    static class Point {
        long x, y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        Point subtract(Point p) {
            return new Point(this.x - p.x, this.y - p.y);
        }

        long getCross(Point p) {
            return this.x * p.y - p.x * this.y;
        }

        long getCcw(Point p1, Point p2) {
            return p1.subtract(this).getCross(p2.subtract(this));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        Point[] polygon = new Point[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            polygon[i] = new Point(x, y);
        }

        long twoTimesArea = 0;

        for (int i = 2; i < n; i++) {
            twoTimesArea += polygon[0].getCcw(polygon[i - 1], polygon[i]);
        }

        double area = Math.abs(twoTimesArea) * 0.5;
        System.out.printf("%.1f%n", area);

        br.close();
    }

}
