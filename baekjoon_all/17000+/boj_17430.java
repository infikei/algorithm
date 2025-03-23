// Solve 2024-07-15
// Update 2025-03-20

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class boj_17430 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            HashSet<Integer> xSet = new HashSet<Integer>();
            HashSet<Integer> ySet = new HashSet<Integer>();

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                xSet.add(x);
                ySet.add(y);
            }

            if (n == (long) xSet.size() * ySet.size()) {
                sb.append("BALANCED\n");
            } else {
                sb.append("NOT BALANCED\n");
            }
        }

        System.out.print(sb);
    }

}
