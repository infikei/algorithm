// Solve 2026-04-07

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2819 {

    static final int CENTER = 1000003;

    static long[] prefixX = new long[CENTER * 2 + 1];
    static long[] prefixY = new long[CENTER * 2 + 1];
    static int[] dx = new int[128];
    static int[] dy = new int[128];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            x += CENTER;
            y += CENTER;

            prefixX[0] += x;
            prefixX[1]--;
            prefixX[x + 1] += 2;

            prefixY[0] += y;
            prefixY[1]--;
            prefixY[y + 1] += 2;
        }

        for (int i = 2; i <= CENTER * 2; i++) {
            prefixX[i] += prefixX[i - 1];
            prefixX[i - 1] += prefixX[i - 2];
            prefixY[i] += prefixY[i - 1];
            prefixY[i - 1] += prefixY[i - 2];
        }

        dx['S'] = 0;
        dy['S'] = 1;

        dx['J'] = 0;
        dy['J'] = -1;

        dx['I'] = 1;
        dy['I'] = 0;

        dx['Z'] = -1;
        dy['Z'] = 0;

        String cmds = br.readLine();
        int sx = CENTER;
        int sy = CENTER;
        StringBuilder sb = new StringBuilder();

        for (char c : cmds.toCharArray()) {
            sx += dx[c];
            sy += dy[c];
            sb.append(prefixX[sx] + prefixY[sy]).append('\n');
        }

        System.out.print(sb);
    }

}
