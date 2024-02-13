// Solve 2024-02-13

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_6808 {

    static int[] myNumbers = new int[9];
    static int[] otherNumbers = new int[9];
    static int winCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int selected = 0;

            for (int i = 0; i < 9; i++) {
                myNumbers[i] = Integer.parseInt(st.nextToken());
                selected |= 1 << myNumbers[i];
            }

            for (int num = 1, idx = 0; num <= 18; num++) {
                if ((selected & 1 << num) == 0) {
                    otherNumbers[idx++] = num;
                }
            }

            winCount = 0;
            dfs(0, 0, 0);
            sb.append("#").append(ti).append(" ").append(winCount).append(" ").append(362880 - winCount).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static void dfs(int depth, int selected, int curScore) {
        if (depth == 9) {
            if (curScore > 85) {
                winCount++;
            }

            return;
        }

        for (int i = 0; i < 9; i++) {
            if ((selected & 1 << i) == 0) {
                dfs(depth + 1, selected | 1 << i, curScore + (myNumbers[depth] > otherNumbers[i] ? myNumbers[depth] + otherNumbers[i] : 0));
            }
        }
    }

}
