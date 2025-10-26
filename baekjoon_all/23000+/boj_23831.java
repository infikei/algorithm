// Solve 2025-10-26

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_23831 {

    static final int INF = 0x3f3f3f3f;

    static int n, a, b;
    static int[][] score = new int[100][3];
    static int[][][][] memo = new int[100][3][101][101];

    static int recur(int cur, int curPlace, int cnt1, int cnt2) {
        if (cur == n) {
            return cnt1 < b ? -INF : 0;
        }

        if (memo[cur][curPlace][cnt1][cnt2] != 0) {
            return memo[cur][curPlace][cnt1][cnt2];
        }

        int mx = -INF;

        for (int i = 0; i < 3; i++) {
            int nxtCnt2 = cnt2 + (curPlace == 2 ? 1 : 0);

            if (nxtCnt2 > a) continue;
            if (i == 1 && curPlace == 1) continue;

            int nxtCnt1 = cnt1 + (curPlace == 0 ? 1 : 0);
            nxtCnt1 = nxtCnt1 > b ? b : nxtCnt1;

            int res = score[cur][curPlace] + recur(cur + 1, i, nxtCnt1, nxtCnt2);
            mx = res > mx ? res : mx;
        }

        memo[cur][curPlace][cnt1][cnt2] = mx;
        return mx;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            score[i][0] = Math.max(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            score[i][1] = Integer.parseInt(st.nextToken());
            score[i][2] = Integer.parseInt(st.nextToken());
        }

        int mx = 0;

        for (int i = 0; i < 3; i++) {
            mx = Math.max(mx, recur(0, i, 0, 0));
        }

        System.out.println(mx);
    }

}
