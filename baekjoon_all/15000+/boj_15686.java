// Solve 2024-01-22
// Update 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_15686 {

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

    static int n, m;
    static ArrayList<Point> houses;
    static ArrayList<Point> chickens;
    static int[] chickenSelected;
    static int minSumChickenDist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        houses = new ArrayList<Point>();
        chickens = new ArrayList<Point>();

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                int val = Integer.parseInt(st.nextToken());

                if (val == 1) {
                    houses.add(new Point(x, y));
                } else if (val == 2) {
                    chickens.add(new Point(x, y));
                }
            }
        }

        chickenSelected = new int[m];
        minSumChickenDist = 10000;
        dfs(0, 0);
        System.out.println(minSumChickenDist);
        br.close();
    }

    static void dfs(int depth, int beginIdx) {
        if (depth == m) {
            int curSumChickenDist = 0;

            for (Point house : houses) {
                curSumChickenDist += getChickenDistOf(house);
            }

            minSumChickenDist = Math.min(minSumChickenDist, curSumChickenDist);
            return;
        }

        for (int i = beginIdx; i < chickens.size(); i++) {
            chickenSelected[depth] = i;
            dfs(depth + 1, i + 1);
        }
    }

    static int getChickenDistOf(Point house) {
        int chickenDist = 100;

        for (int chickenIdx : chickenSelected) {
            chickenDist = Math.min(chickenDist, house.getDist(chickens.get(chickenIdx)));
        }

        return chickenDist;
    }

}
