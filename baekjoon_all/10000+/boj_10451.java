// Solve 2024-05-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_10451 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        int[] arr = new int[1001];

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            int cycleCount = 0;
            boolean[] visited = new boolean[n + 1];

            for (int i = 1; i <= n; i++) {
                if (visited[i]) {
                    continue;
                }

                cycleCount++;
                visited[i] = true;
                int ni = arr[i];

                while (ni != i) {
                    visited[ni] = true;
                    ni = arr[ni];
                }
            }

            sb.append(cycleCount).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
