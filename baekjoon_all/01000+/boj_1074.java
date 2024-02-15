// Solve 2024-02-14
// Update 2024-02-15

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1074 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int curDepth = n;
        int curNum = 0;

        while (--curDepth >= 0) {
            int subArea = 1 << (curDepth * 2);

            if (r >= (1 << curDepth)) {
                curNum += subArea * 2;
                r -= 1 << curDepth;
            }

            if (c >= (1 << curDepth)) {
                curNum += subArea;
                c -= 1 << curDepth;
            }
        }

        System.out.println(curNum);
        br.close();
    }

}
