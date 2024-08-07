// Solve 2024-07-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_31669 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[] checked = new boolean[m];

        for (int i = 0; i < n; i++) {
            String timeTable = br.readLine();

            for (int j = 0; j < m; j++) {
                if (timeTable.charAt(j) == 'O') {
                    checked[j] = true;
                }
            }
        }

        int ans = -1;

        for (int j = 0; j < m; j++) {
            if (!checked[j]) {
                ans = j + 1;
                break;
            }
        }

        if (ans == -1) {
            System.out.println("ESCAPE FAILED\n");
        } else {
            System.out.println(ans);
        }

        br.close();
    }

}
