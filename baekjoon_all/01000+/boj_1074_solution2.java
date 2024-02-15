// Solve 2024-02-14
// Update 2024-02-15

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1074_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        System.out.println(recur(1 << n, r, c));
        br.close();
    }

    static int recur(int size, int r, int c) {
        if (size == 1) return 0;

        int halfSize = size / 2;

        if (r < halfSize) {
            if (c < halfSize) {
                return recur(halfSize, r, c);
            } else {
                return halfSize * halfSize + recur(halfSize, r, c - halfSize);
            }
        } else {
            if (c < halfSize) {
                return halfSize * halfSize * 2 + recur(halfSize, r - halfSize, c);
            } else {
                return halfSize * halfSize * 3 + recur(halfSize, r - halfSize, c - halfSize);
            }
        }
    }

}
