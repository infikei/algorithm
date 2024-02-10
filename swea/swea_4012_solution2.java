// Solve 2024-02-08

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_4012_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            int[][] board = new int[n][n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int j = 0; j < i; j++) {
                    board[j][i] += Integer.parseInt(st.nextToken());
                }

                for (int j = i; j < n; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int[] selected = new int[n];

            for (int i = n / 2; i < n; i++) {
                selected[i] = 1;
            }

            int minDiff = Integer.MAX_VALUE;

            do {
                int foodA = 0;
                int foodB = 0;

                for (int i = 0; i < n; i++) {
                    if (selected[i] == 1) continue;

                    for (int j = i + 1; j < n; j++) {
                        if (selected[j] == 1) continue;

                        foodA += board[i][j];
                    }
                }

                for (int i = 0; i < n; i++) {
                    if (selected[i] == 0) continue;

                    for (int j = i + 1; j < n; j++) {
                        if (selected[j] == 0) continue;

                        foodB += board[i][j];
                    }
                }

                minDiff = Math.min(minDiff, Math.abs(foodA - foodB));
            } while (nextPermutation(selected));

            sb.append("#").append(ti).append(" ").append(minDiff).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static boolean nextPermutation(int[] p) {
        final int N = p.length;

        int i = N - 1;

        while (i > 0 && p[i - 1] >= p[i]) {
            i--;
        }

        if (i == 0) return false;

        int j = N - 1;

        while (p[i - 1] >= p[j]) {
            j--;
        }

        swap(p, i - 1, j);

        j = N - 1;

        while (i < j) {
            swap(p, i++, j--);
        }

        return true;
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}
