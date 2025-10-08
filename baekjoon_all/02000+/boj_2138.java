// Solve 2024-06-23
// Update 2025-10-08

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2138 {

    static final int INF = 1000000000;

    static int getClickCnt(int n, int[] board, int[] target) {
        int ret = 0;

        for (int i = 1; i < n; i++) {
            if (board[i - 1] != target[i - 1]) {
                ret++;
                board[i - 1] ^= 1;
                board[i] ^= 1;
                board[i + 1] ^= 1;
            }
        }

        return board[n - 1] != target[n - 1] ? INF : ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] board1 = new int[n + 1];
        int[] board2 = new int[n + 1];
        int[] target = new int[n + 1];
        String s = br.readLine();

        for (int i = 0; i < n; i++) {
            board2[i] = board1[i] = s.charAt(i) - '0';
        }

        s = br.readLine();

        for (int i = 0; i < n; i++) {
            target[i] = s.charAt(i) - '0';
        }

        int res1 = getClickCnt(n, board1, target);

        board2[0] ^= 1;
        board2[1] ^= 1;
        int res2 = 1 + getClickCnt(n, board2, target);

        int ans = Math.min(res1, res2);
        System.out.println(ans == INF ? -1 : ans);
    }

}
