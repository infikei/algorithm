// Solve 2024-04-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_18427 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        final int MOD = 10007;
        int[] memo = new int[h + 1];
        memo[0] = 1;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            ArrayList<Integer> blocks = new ArrayList<Integer>();

            while (st.hasMoreTokens()) {
                blocks.add(Integer.parseInt(st.nextToken()));
            }

            for (int j = h; j >= 0; j--) {
                for (int block : blocks) {
                    if (j - block >= 0) {
                        memo[j] += memo[j - block];
                    }
                }

                memo[j] %= MOD;
            }
        }

        System.out.println(memo[h]);
        br.close();
    }

}
