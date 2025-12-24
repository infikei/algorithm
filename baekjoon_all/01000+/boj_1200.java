// Solve 2025-12-23

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_1200 {

    static int n, m, r, s;
    static int[][] board;
    static int[][] prefix;
    static int[] selected;
    static int[] vs;
    static int[] v;
    static int mn = 0x3f3f3f3f;

    static boolean check(int limit) {
        Arrays.fill(vs, 0);
        int cnt = 0;

        for (int y = 1; y <= m; y++) {
            int mxV = 0;
            int mxVs = 0;

            for (int i = 1; i <= r + 1; i++) {
                int x0 = selected[i - 1];
                int x = selected[i];
                v[i] = prefix[x][y] - prefix[x0][y];
                mxV = Math.max(mxV, v[i]);
                vs[i] += v[i];
                mxVs = Math.max(mxVs, vs[i]);
            }

            if (mxV > limit) {
                return false;
            }

            if (mxVs > limit) {
                cnt++;

                if (cnt > s) {
                    return false;
                }

                for (int i = 1; i <= r + 1; i++) {
                    vs[i] = v[i];
                }
            }
        }

        return true;
    }

    static void recur(int depth, int idxFrom) {
        if (depth == r + 1) {
            int low = 0;
            int high = mn;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (check(mid)) {
                    mn = Math.min(mn, mid);
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            return;
        }

        for (int i = idxFrom; i < n; i++) {
            selected[depth] = i;
            recur(depth + 1, i + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        board = new int[n + 1][m + 1];
        prefix = new int[n + 1][m + 1];

        for (int x = 1; x <= n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 1; y <= m; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
                prefix[x][y] = board[x][y] + prefix[x - 1][y];
            }
        }

        selected = new int[r + 2];
        selected[r + 1] = n;
        vs = new int[r + 2];
        v = new int[r + 2];
        recur(1, 1);
        System.out.println(mn);
    }

}
