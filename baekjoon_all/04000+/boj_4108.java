// Solve 2025-02-24

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_4108 {

    static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        char[][] board = new char[100][100];

        while (true) {
            st = new StringTokenizer(br.readLine(), " ");
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (r == 0 && c == 0) break;

            for (int x = 0; x < r; x++) {
                String line = br.readLine();

                for (int y = 0; y < c; y++) {
                    board[x][y] = line.charAt(y);
                }
            }

            for (int x = 0; x < r; x++) {
                for (int y = 0; y < c; y++) {
                    if (board[x][y] == '*') {
                        sb.append('*');
                        continue;
                    }

                    int cnt = 0;

                    for (int d = 0; d < 8; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '*') {
                            cnt++;
                        }
                    }

                    sb.append((char) ('0' + cnt));
                }

                sb.append('\n');
            }
        }

        System.out.print(sb);
    }

}
