// Solve 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2564 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine());
        int[] position = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int direction = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());

            switch (direction) {
                case 1:
                    position[i] = dist;
                    break;
                case 2:
                    position[i] = w * 2 + h - dist;
                    break;
                case 3:
                    position[i] = (w + h) * 2 - dist;
                    break;
                case 4:
                    position[i] = w + dist;
                    break;
            }
        }

        int distSum = 0;

        for (int i = 0; i < n; i++) {
            int dist = Math.abs(position[i] - position[n]);
            dist = Math.min(dist, (w + h) * 2 - dist);
            distSum += dist;
        }

        System.out.println(distSum);
        br.close();
    }

}
