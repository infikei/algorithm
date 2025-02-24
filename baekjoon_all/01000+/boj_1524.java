// Solve 2025-02-22

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1524 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            br.readLine();
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine(), " ");
            int maxS = 0;

            while (n-- > 0) {
                int s = Integer.parseInt(st.nextToken());
                maxS = s > maxS ? s : maxS;
            }

            st = new StringTokenizer(br.readLine(), " ");
            int maxB = 0;

            while (m-- > 0) {
                int b = Integer.parseInt(st.nextToken());
                maxB = b > maxB ? b : maxB;
            }

            sb.append(maxS >= maxB ? "S\n" : "B\n");
        }

        System.out.println(sb);
    }

}
