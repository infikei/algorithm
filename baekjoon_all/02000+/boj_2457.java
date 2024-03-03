// Solve 2024-02-26
// Update 2024-03-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2457 {

    static int[] days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    public static void main(String[] args) throws IOException {
        for (int i = 1; i < 13; i++) {
            days[i] += days[i - 1];
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int[] memoNext = new int[366];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int monthBegin = Integer.parseInt(st.nextToken());
            int dayBegin = Integer.parseInt(st.nextToken());
            int monthEnd = Integer.parseInt(st.nextToken());
            int dayEnd = Integer.parseInt(st.nextToken());

            int begin = days[monthBegin - 1] + dayBegin;
            int end = days[monthEnd - 1] + dayEnd;

            for (int d = begin; d < end; d++) {
                memoNext[d] = Math.max(memoNext[d], end);
            }
        }

        int curDay = 60;
        int curCount = 0;

        while (curDay < 335) {
            curDay = memoNext[curDay];
            curCount++;

            if (curDay == 0) {
                curCount = 0;
                break;
            }
        }

        System.out.println(curCount);
        br.close();
    }

}
