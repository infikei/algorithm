// Solve 2024-01-30
// Update 2024-01-31

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1244 {

    static int n;
    static int[] switches;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        switches = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            switches[i] = Integer.parseInt(st.nextToken());
        }

        int q = Integer.parseInt(br.readLine());

        for (int qi = 0; qi < q; qi++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            if (cmd == 1) {
                switchBoy(x);
            } else {
                switchGirl(x);
            }
        }

        StringBuilder sb = new StringBuilder();
        int iMod20 = 0;

        for (int i = 1; i <= n; i++) {
            sb.append(switches[i]).append(" ");

            if (++iMod20 == 20 && i != n) {
                sb.append("\n");
                iMod20 = 0;
            }
        }

        System.out.println(sb);
        br.close();
    }

    static void switchBoy(int x) {
        for (int i = x; i <= n; i += x) {
            switches[i] ^= 1;
        }
    }

    static void switchGirl(int x) {
        switches[x] ^= 1;
        int xBegin = x;
        int xEnd = x;

        while (--xBegin >= 1 && ++xEnd <= n && switches[xBegin] == switches[xEnd]) {
            switches[xBegin] ^= 1;
            switches[xEnd] ^= 1;
        }
    }

}
