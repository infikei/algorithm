// Solve 2025-02-17

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2668 {

    static void initArr(boolean[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        boolean[] visited = new boolean[n + 1];
        StringBuilder sb = new StringBuilder();
        int cnt = 0;

        for (int u = 1; u <= n; u++) {
            initArr(visited);

            int nu = arr[u];
            visited[nu] = true;

            while (nu != u && !visited[arr[nu]]) {
                nu = arr[nu];
                visited[nu] = true;
            }

            if (nu == u) {
                sb.append(u).append("\n");
                cnt++;
            }
        }

        System.out.println(cnt);
        System.out.println(sb);
    }

}
