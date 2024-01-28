// Solve 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2563 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        boolean[][] board = new boolean[100][100];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int xBegin = Integer.parseInt(st.nextToken());
            int yBegin = Integer.parseInt(st.nextToken());
            int xEnd = xBegin + 10;
            int yEnd = yBegin + 10;

            for (int x = xBegin; x < xEnd; x++) {
                for (int y = yBegin; y < yEnd; y++) {
                    board[x][y] = true;
                }
            }
        }

        int ans = 0;

        for (int x = 0; x < 100; x++) {
            for (int y = 0; y < 100; y++) {
                if (board[x][y]) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
        br.close();
    }

}
