// Solve 2024-02-16

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea_5644 {

    static class BatteryCharger implements Comparable<BatteryCharger> {
        int idx, x, y, coverage, performance;

        BatteryCharger(int idx, int x, int y, int coverage, int performance) {
            this.idx = idx;
            this.x = x;
            this.y = y;
            this.coverage = coverage;
            this.performance = performance;
        }

        boolean contains(int x, int y) {
            return Math.abs(this.x - x) + Math.abs(this.y - y) <= this.coverage;
        }

        @Override
        public int compareTo(BatteryCharger o) {
            if (this.performance != o.performance) return o.performance - this.performance;
            return this.idx - o.idx;
        }
    }

    static int[] dx = { 0, -1, 0, 1, 0 };
    static int[] dy = { 0, 0, 1, 0, -1 };
    static int m, a;
    static int[][] users;
    static BatteryCharger[] batteryChargers;

    static int charge(int ax, int ay, int bx, int by) {
        ArrayList<Integer> aBCList = new ArrayList<Integer>();
        ArrayList<Integer> bBCList = new ArrayList<Integer>();

        for (int i = 0; i < a; i++) {
            if (batteryChargers[i].contains(ax, ay)) {
                aBCList.add(i);
            }

            if (batteryChargers[i].contains(bx, by)) {
                bBCList.add(i);
            }
        }

        if (aBCList.isEmpty()) {
            if (bBCList.isEmpty()) {
                return 0;
            }

            return batteryChargers[bBCList.get(0)].performance;
        }

        if (bBCList.isEmpty()) {
            return batteryChargers[aBCList.get(0)].performance;
        }

        if (aBCList.get(0) == bBCList.get(0)) {
            if (aBCList.size() == 1 && bBCList.size() == 1) {
                return batteryChargers[aBCList.get(0)].performance;
            } else if (aBCList.size() == 1) {
                return batteryChargers[aBCList.get(0)].performance + batteryChargers[bBCList.get(1)].performance;
            } else if (bBCList.size() == 1) {
                return batteryChargers[aBCList.get(1)].performance + batteryChargers[bBCList.get(0)].performance;
            } else {
                return batteryChargers[aBCList.get(0)].performance + Math.max(batteryChargers[aBCList.get(1)].performance, batteryChargers[bBCList.get(1)].performance);
            }
        }

        return batteryChargers[aBCList.get(0)].performance + batteryChargers[bBCList.get(0)].performance;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            m = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            users = new int[2][m];

            for (int i = 0; i < 2; i++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int j = 0; j < m; j++) {
                    users[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            batteryChargers = new BatteryCharger[a];

            for (int i = 0; i < a; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int coverage = Integer.parseInt(st.nextToken());
                int performance = Integer.parseInt(st.nextToken());

                batteryChargers[i] = new BatteryCharger(i, x, y, coverage, performance);
            }

            Arrays.sort(batteryChargers);

            int ax = 1, ay = 1;
            int bx = 10, by = 10;
            int chargingSum = charge(ax, ay, bx, by);

            for (int i = 0; i < m; i++) {
                ax += dx[users[0][i]];
                ay += dy[users[0][i]];
                bx += dx[users[1][i]];
                by += dy[users[1][i]];
                chargingSum += charge(ax, ay, bx, by);
            }

            sb.append("#").append(ti).append(" ").append(chargingSum).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
