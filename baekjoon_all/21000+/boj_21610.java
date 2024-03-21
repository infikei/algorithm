// Solve 2024-03-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_21610 {

    static int[] dx = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
    static int[] dy = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] water = new int[n][n];
        int[][] waterAdd = new int[n][n];
        ArrayList<int[]> clouds = new ArrayList<int[]>();

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                water[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        clouds.add(new int[] { n - 2, 0 });
        clouds.add(new int[] { n - 2, 1 });
        clouds.add(new int[] { n - 1, 0 });
        clouds.add(new int[] { n - 1, 1 });

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int di = Integer.parseInt(st.nextToken());
            int si = Integer.parseInt(st.nextToken());

            for (int[] cloud : clouds) {
                cloud[0] = (cloud[0] + dx[di] * si + n * 25) % n;
                cloud[1] = (cloud[1] + dy[di] * si + n * 25) % n;
                water[cloud[0]][cloud[1]]++;
                waterAdd[cloud[0]][cloud[1]]++;
            }

            for (int[] cloud : clouds) {
                for (int d = 2; d <= 8; d += 2) {
                    int nx = cloud[0] + dx[d];
                    int ny = cloud[1] + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && water[nx][ny] > 0) {
                        waterAdd[cloud[0]][cloud[1]]++;
                    }
                }
            }

            for (int[] cloud : clouds) {
                water[cloud[0]][cloud[1]] += waterAdd[cloud[0]][cloud[1]] - 1;
            }

            clouds.clear();

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (waterAdd[x][y] > 0) {
                        waterAdd[x][y] = 0;
                    } else {
                        if (water[x][y] >= 2) {
                            water[x][y] -= 2;
                            clouds.add(new int[] { x, y });
                        }
                    }
                }
            }
        }

        int waterSum = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                waterSum += water[x][y];
            }
        }

        System.out.println(waterSum);
        br.close();
    }

}
