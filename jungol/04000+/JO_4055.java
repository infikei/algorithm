// Solve 2026-06-21

import java.io.*;
import java.util.*;

public class JO_4055 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<int[]> intervals = new ArrayList<>();
        intervals.add(new int[] {0, 0});

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            intervals.add(new int[] {s, e});
        }

        if (n <= 1) {
            System.out.println(0);
            return;
        }

        Collections.sort(intervals, (o1, o2) -> o1[1] - o2[1]);
        int[] memo = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            int s = Math.max(intervals.get(i - 1)[1], intervals.get(i)[0]);
            int e = intervals.get(i)[1];
            memo[i] = memo[i - 1] + (e - s);
        }

        int[] memo2 = new int[n + 1];

        for (int i = 2; i <= n; i++) {
            int s = Math.max(intervals.get(i - 1)[1], intervals.get(i)[0]);
            int e = intervals.get(i)[1];
            memo2[i] = memo2[i - 1] + (e - s);

            s = Math.max(intervals.get(i - 2)[1], intervals.get(i)[0]);
            e = intervals.get(i)[1];
            memo2[i] = Math.max(memo2[i], memo[i - 2] + (e - s));
        }

        System.out.println(Math.max(memo[n - 1], memo2[n]));
    }

}
