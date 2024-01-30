// Solve 2024-01-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_18511 {

    static int n, k;
    static int nStrLen;
    static int[] digits;
    static int ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        String nStr = st.nextToken();
        nStrLen = nStr.length();
        n = Integer.parseInt(nStr);
        k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        digits = new int[k];

        for (int i = 0; i < k; i++) {
            digits[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(digits);
        ans = -1;
        dfs(0, 0);
        System.out.println(ans);
        br.close();
    }

    static boolean dfs(int depth, int num) {
        if (depth == nStrLen) {
            if (num <= n) {
                ans = num;
                return true;
            }

            return false;
        }

        for (int i = k - 1; i >= 0; i--) {
            if (dfs(depth + 1, num * 10 + digits[i])) {
                return true;
            }
        }

        if (num == 0) {
            if (dfs(depth + 1, 0)) {
                return true;
            }
        }

        return false;
    }

}
