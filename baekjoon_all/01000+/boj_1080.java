// Solve 2024-06-21
// Update 2025-11-10

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1080 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] a = new int[n][m];
        int[][] b = new int[n][m];

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < m; y++) {
                a[x][y] = row.charAt(y) - '0';
            }
        }

        for (int x = 0; x < n; x++) {
            String row = br.readLine();

            for (int y = 0; y < m; y++) {
                b[x][y] = row.charAt(y) - '0';
            }
        }

        int cnt = 0;

        for (int x = 2; x < n; x++) {
            for (int y = 2; y < m; y++) {
                if (a[x - 2][y - 2] == b[x - 2][y - 2]) continue;

                cnt++;

                for (int nx = x - 2; nx <= x; nx++) {
                    for (int ny = y - 2; ny <= y; ny++) {
                        a[nx][ny] ^= 1;
                    }
                }
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (a[x][y] != b[x][y]) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        System.out.println(cnt);
    }

}
