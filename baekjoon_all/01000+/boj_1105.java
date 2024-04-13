// Solve 2024-04-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1105 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        char[] left = st.nextToken().toCharArray();
        int right = Integer.parseInt(st.nextToken());

        int minEightCnt = 0;

        for (int i = 0; i < left.length; i++) {
            if (left[i] == '8') {
                minEightCnt++;
            }
        }

        for (int i = left.length - 1; i >= 0; i--) {
            if (left[i] != '8') continue;

            left[i] = '9';

            for (int j = i + 1; j < left.length; j++) {
                left[j] = '0';
            }

            if (Integer.parseInt(String.valueOf(left)) > right) break;

            minEightCnt--;
        }

        System.out.println(minEightCnt);
        br.close();
    }

}
