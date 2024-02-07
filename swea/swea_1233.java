// Solve 2024-02-06

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_1233 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        for (int ti = 1; ti <= 10; ti++) {
            int n = Integer.parseInt(br.readLine());
            int flagValid = 1;

            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                st.nextToken();
                String str = st.nextToken();
                char ch = str.charAt(0);
                int childrenNum = st.countTokens();

                if (childrenNum == 2) {
                    if (ch >= '0' && ch <= '9') {
                        flagValid = 0;
                    }
                } else if (childrenNum == 0) {
                    if (ch < '0' || ch > '9') {
                        flagValid = 0;
                    }
                } else {
                    flagValid = 0;
                }
            }

            sb.append("#").append(ti).append(" ").append(flagValid).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
