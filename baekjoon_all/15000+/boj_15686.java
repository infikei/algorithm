// Solve 2024-01-22

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_15686 {
    private static int n, m;
    private static int minDistSum;
    private static List<int[]> houseList;
    private static List<int[]> chickenList;
    private static int[][] chickenSelected;

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
                    houseList.add(new int[] { i, j });
                } else if (x == 2) {
                    chickenList.add(new int[] { i, j });
                }
            }
        }

        minDistSum = 10000;
        chickenSelected = new int[m][];
        dfs(0, 0);
        System.out.println(minDistSum);
        br.close();
    }

    private static void dfs(int depth, int idx) {
        if (depth == m) {
            int curDistSum = 0;

            for (int[] house : houseList) {
                curDistSum += calcChickenDistOf(house);
            }

            minDistSum = Math.min(minDistSum, curDistSum);
            return;
        }

        for (int i = idx; i < chickenList.size(); i++) {
            chickenSelected[depth] = chickenList.get(i);
            dfs(depth + 1, i + 1);
        }
    }

    private static int calcChickenDistOf(int[] house) {
        int chickenDist = 100;

        for (int[] chicken : chickenSelected) {
            chickenDist = Math.min(chickenDist, calcDistBetween(house, chicken));
        }

        return chickenDist;
    }

    private static int calcDistBetween(int[] house, int[] chicken) {
        return Math.abs(house[0] - chicken[0]) + Math.abs(house[1] - chicken[1]);
    }
}
