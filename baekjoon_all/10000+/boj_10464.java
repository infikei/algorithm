// Solve 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_10464 {

    static int xorFromZero(int n) {
        int left = n % 2 == 0 ? n : 0;
        int right = (n % 4 == 1 || n % 4 == 2) ? 1 : 0;
        return left + right;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int start = Integer.parseInt(st.nextToken());
            int finish = Integer.parseInt(st.nextToken());
            sb.append(xorFromZero(start - 1) ^ xorFromZero(finish)).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
