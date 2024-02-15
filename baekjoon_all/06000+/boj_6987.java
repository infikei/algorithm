// Solve 2024-02-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_6987 {

    static int[][] combArr;
    static int[] win;
    static int[] draw;
    static int[] lose;

    public static void main(String[] args) throws IOException {
        combArr = new int[15][2];
        int idx = 0;

        for (int i = 0; i < 6; i++) {
            for (int j = i + 1; j < 6; j++) {
                combArr[idx++] = new int[] { i, j };
            }
        }

        win = new int[6];
        draw = new int[6];
        lose = new int[6];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        for (int ti = 1; ti <= 4; ti++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < 6; i++) {
                win[i] = Integer.parseInt(st.nextToken());
                draw[i] = Integer.parseInt(st.nextToken());
                lose[i] = Integer.parseInt(st.nextToken());
            }

            sb.append(dfs(0) ? "1 " : "0 ");
        }

        System.out.println(sb);
        br.close();
    }

    static boolean dfs(int depth) {
        if (depth == 15) {
            for (int i = 0; i < 6; i++) {
                if (win[i] != 0 || draw[i] != 0 || lose[i] != 0) {
                    return false;
                }
            }

            return true;
        }

        int a = combArr[depth][0];
        int b = combArr[depth][1];

        if (win[a] >= 1 && lose[b] >= 1) {
            win[a]--;
            lose[b]--;
            if (dfs(depth + 1)) return true;
            win[a]++;
            lose[b]++;
        }

        if (draw[a] >= 1 && draw[b] >= 1) {
            draw[a]--;
            draw[b]--;
            if (dfs(depth + 1)) return true;
            draw[a]++;
            draw[b]++;
        }

        if (lose[a] >= 1 && win[b] >= 1) {
            lose[a]--;
            win[b]--;
            if (dfs(depth + 1)) return true;
            lose[a]++;
            win[b]++;
        }

        return false;
    }

}
