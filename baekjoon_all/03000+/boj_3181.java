// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_3181 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb = new StringBuilder();
        String[] wordsIgnore = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" };

        sb.append((char) (st.nextToken().charAt(0) - 'a' + 'A'));

        while (st.hasMoreTokens()) {
            String s = st.nextToken();
            boolean flagContinue = false;

            for (String w : wordsIgnore) {
                if (s.equals(w)) {
                    flagContinue = true;
                    break;
                }
            }

            if (flagContinue) continue;

            sb.append((char) (s.charAt(0) - 'a' + 'A'));
        }

        System.out.println(sb);
        br.close();
    }

}
