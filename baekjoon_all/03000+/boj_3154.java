// Solve 2025-09-23

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_3154 {

    static int[] x = new int[] {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    static int[] y = new int[] {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

    static int getDist(int d1, int d2) {
        return Math.abs(x[d1] - x[d2]) + Math.abs(y[d1] - y[d2]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String hhmm = br.readLine();
        int h = (hhmm.charAt(0) - '0') * 10 + (hhmm.charAt(1) - '0');
        int m = (hhmm.charAt(3) - '0') * 10 + (hhmm.charAt(4) - '0');
        int hourOfMinEffort = h;
        int minuteOfMinEffort = m;
        int minEffort = 100000;

        for (int i = h; i < 100; i += 24) {
            int d1 = i / 10;
            int d2 = i % 10;
            int e = getDist(d1, d2);

            for (int j = m; j < 100; j += 60) {
                int d3 = j / 10;
                int d4 = j % 10;
                int effort = e + getDist(d2, d3) + getDist(d3, d4);

                if (effort < minEffort) {
                    minEffort = effort;
                    hourOfMinEffort = i;
                    minuteOfMinEffort = j;
                }
            }
        }

        System.out.print(hourOfMinEffort / 10);
        System.out.print(hourOfMinEffort % 10);
        System.out.print(":");
        System.out.print(minuteOfMinEffort / 10);
        System.out.println(minuteOfMinEffort % 10);
    }

}
