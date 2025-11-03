// Solve 2025-10-30

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_25319 {

    static void addMoveCommand(int[] cur, int[] nxt, StringBuilder cmd) {
        while (cur[0] < nxt[0]) {
            cmd.append("D");
            cur[0]++;
        }

        while (cur[0] > nxt[0]) {
            cmd.append("U");
            cur[0]--;
        }

        while (cur[1] < nxt[1]) {
            cmd.append("R");
            cur[1]++;
        }

        while (cur[1] > nxt[1]) {
            cmd.append("L");
            cur[1]--;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] boardCnt = new int[128];
        ArrayDeque<int[]>[] pos = new ArrayDeque[128];

        for (int i = 'a'; i <= 'z'; i++) {
            pos[i] = new ArrayDeque<>();
        }

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < m; y++) {
                boardCnt[row.charAt(y)]++;
                pos[row.charAt(y)].addLast(new int[] {x, y});
            }
        }

        String s = br.readLine();
        int[] sCnt = new int[128];

        for (int i = 0; i < s.length(); i++) {
            sCnt[s.charAt(i)]++;
        }

        int c = 0x3f3f3f3f;

        for (int i = 'a'; i <= 'z'; i++) {
            if (sCnt[i] != 0) {
                c = Math.min(c, boardCnt[i] / sCnt[i]);
            }
        }

        StringBuilder cmd = new StringBuilder();
        int[] cur = new int[] {0, 0};

        for (int i = 0; i < c; i++) {
            for (int j = 0; j < s.length(); j++) {
                int[] nxt = pos[s.charAt(j)].pollFirst();
                addMoveCommand(cur, nxt, cmd);
                cmd.append("P");
            }
        }

        addMoveCommand(cur, new int[] {n - 1, m - 1}, cmd);

        System.out.println(c + " " + cmd.length());
        System.out.println(cmd);
    }

}
