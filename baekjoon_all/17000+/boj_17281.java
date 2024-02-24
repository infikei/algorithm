// Solve 2024-02-23

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17281 {

    static int n;
    static int[][] results;
    static int maxScore;
    static int[] orderToPlayer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        results = new int[n][9];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < 9; j++) {
                results[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        maxScore = 0;
        orderToPlayer = new int[9];
        dfs(0, 0);
        System.out.println(maxScore);
        br.close();
    }

    static void dfs(int depth, int selected) {
        if (depth == 9) {
            int curScore = playBaseball(orderToPlayer);

            if (curScore > maxScore) {
                maxScore = curScore;
            }

            return;
        }

        if (depth == 3) {
            depth++;
        }

        for (int i = 1; i <= 8; i++) {
            if ((selected & 1 << i) == 0) {
                orderToPlayer[depth] = i;
                dfs(depth + 1, selected | 1 << i);
            }
        }
    }

    static int playBaseball(int[] orderToPlayer) {
        int curScore = 0;
        int curInning = 0;
        int curOrder = 0;
        int[] bases = new int[5];

        while (curInning < n) {
            for (int curBase = 0; curBase < 5; curBase++) {
                bases[curBase] = 0;
            }

            int curOuts = 0;

            while (curOuts < 3) {
                int curResult = results[curInning][orderToPlayer[curOrder]];

                if (curResult == 0) {
                    curOuts++;
                } else {
                    bases[0] = 1;

                    for (int curBase = 3; curBase >= 0; curBase--) {
                        if (bases[curBase] == 1) {
                            bases[curBase] = 0;
                            bases[Math.min(curBase + curResult, 4)]++;
                        }
                    }

                    curScore += bases[4];
                    bases[4] = 0;
                }

                if (++curOrder == 9) {
                    curOrder = 0;
                }
            }

            curInning++;
        }

        return curScore;
    }

}
