// Solve 2024-03-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1891 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        String s = st.nextToken();
        s = st.nextToken();
        st = new StringTokenizer(br.readLine(), " ");
        long dy = Long.parseLong(st.nextToken());
        long dx = Long.parseLong(st.nextToken());
        dx = -dx;
        long x = 0;
        long y = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '1') {
                y |= 1L << (s.length() - 1 - i);
            } else if (c == '3') {
                x |= 1L << (s.length() - 1 - i);
            } else if (c == '4') {
                x |= 1L << (s.length() - 1 - i);
                y |= 1L << (s.length() - 1 - i);
            }
        }

        x += dx;
        y += dy;
        StringBuilder sb = new StringBuilder();

        if (x < 0L || x >= (1L << s.length()) || y < 0L || y >= (1L << s.length())) {
            sb.append("-1");
        } else {
            char[] answerArr = new char[s.length()];

            for (int i = s.length() - 1; i >= 0; i--) {
                if ((x & 1L) == 0L) {
                    if ((y & 1L) == 0L) {
                        answerArr[i] = '2';
                    } else {
                        answerArr[i] = '1';
                    }
                } else {
                    if ((y & 1L) == 0L) {
                        answerArr[i] = '3';
                    } else {
                        answerArr[i] = '4';
                    }
                }

                x >>= 1;
                y >>= 1;
            }

            for (int i = 0; i < s.length(); i++) {
                sb.append(answerArr[i]);
            }
        }

        System.out.println(sb);
        br.close();
    }

}
