// Solve 2024-01-22
// Update 2024-01-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_15686 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int n, m;
    static List<Point> houseList;
    static List<Point> chickenList;
    static Point[] chickenSelected;
    static int minChickenDistSum;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        houseList = new ArrayList<>();
        chickenList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < n; j++) {
                int x = Integer.parseInt(st.nextToken());

                if (x == 1) {
                    houseList.add(new Point(i, j));
                } else if (x == 2) {
                    chickenList.add(new Point(i, j));
                }
            }
        }

        minChickenDistSum = 10000;
        chickenSelected = new Point[m];
        dfs(0, 0);
        System.out.println(minChickenDistSum);
        br.close();
    }

    static void dfs(int depth, int idx) {
        if (depth == m) {
            int chickenDistSum = 0;

            for (Point house : houseList) {
                chickenDistSum += calcChickenDistOf(house);
            }

            minChickenDistSum = Math.min(minChickenDistSum, chickenDistSum);
            return;
        }

        for (int i = idx; i < chickenList.size(); i++) {
            chickenSelected[depth] = chickenList.get(i);
            dfs(depth + 1, i + 1);
        }
    }

    static int calcChickenDistOf(Point house) {
        int chickenDist = 100;

        for (Point chicken : chickenSelected) {
            chickenDist = Math.min(chickenDist, calcDistBetween(house, chicken));
        }

        return chickenDist;
    }

    static int calcDistBetween(Point p1, Point p2) {
        return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
    }

}
