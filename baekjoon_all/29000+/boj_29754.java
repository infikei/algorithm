// Solve 2025-11-15

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class boj_29754 {

    static int getMinutes(String hhmm) {
        return (hhmm.charAt(0) - '0') * 600
                + (hhmm.charAt(1) - '0') * 60
                + (hhmm.charAt(3) - '0') * 10
                + (hhmm.charAt(4) - '0');
    }

    static boolean isRealVirtualYoutuber(int[][] weekStatistics) {
        for (int i = 0; i < weekStatistics.length; i++) {
            if (weekStatistics[i][0] < 5 || weekStatistics[i][1] < 3600) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken()) / 7;
        HashMap<String, int[][]> weekStatisticsMap = new HashMap<>();

        while (n-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            String name = st.nextToken();
            int day = Integer.parseInt(st.nextToken());
            int week = (day - 1) / 7;
            int minutes = -getMinutes(st.nextToken()) + getMinutes(st.nextToken());
            int[][] arr;

            if (weekStatisticsMap.containsKey(name)) {
                arr = weekStatisticsMap.get(name);
            } else {
                arr = new int[m][2];
                weekStatisticsMap.put(name, arr);
            }

            arr[week][0]++;
            arr[week][1] += minutes;
        }

        ArrayList<String> realVirtualYoutubers = new ArrayList<>();

        for (Map.Entry<String, int[][]> e : weekStatisticsMap.entrySet()) {
            if (isRealVirtualYoutuber(e.getValue())) {
                realVirtualYoutubers.add(e.getKey());
            }
        }

        if (realVirtualYoutubers.isEmpty()) {
            System.out.println(-1);
            return;
        }

        Collections.sort(realVirtualYoutubers);
        StringBuilder sb = new StringBuilder();

        for (String name : realVirtualYoutubers) {
            sb.append(name).append('\n');
        }

        System.out.print(sb);
    }

}
