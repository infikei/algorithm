// Solve 2025-02-20

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_3711 {

    static void initArr(boolean[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] id = new int[300];
        boolean[] visited = new boolean[50000];

        while (n-- > 0) {
            int g = Integer.parseInt(br.readLine());

            for (int i = 0; i < g; i++) {
                id[i] = Integer.parseInt(br.readLine());
            }

            int m = g;

            while (true) {
                initArr(visited);
                boolean unique = true;

                for (int i = 0; i < g; i++) {
                    int ii = id[i] % m;

                    if (visited[ii]) {
                        unique = false;
                        break;
                    }

                    visited[ii] = true;
                }

                if (unique) break;

                m++;
            }

            sb.append(m).append('\n');
        }

        System.out.println(sb);
    }

}
