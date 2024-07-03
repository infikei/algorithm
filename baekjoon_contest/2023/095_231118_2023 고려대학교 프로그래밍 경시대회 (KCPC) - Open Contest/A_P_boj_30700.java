// Solve 2023-11-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A_P_boj_30700 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        br.close();

        String korea = "KOREA";
        int posKorea = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == korea.charAt(posKorea)) {
                ans++;
                posKorea++;

                if (posKorea == 5) {
                    posKorea = 0;
                }
            }
        }

        System.out.println(ans);
    }
}
