// Solve 2024-08-15
// Update 2025-05-02

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_14910 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int x0 = Integer.parseInt(st.nextToken());

        while (st.hasMoreTokens()) {
            int x = Integer.parseInt(st.nextToken());

            if (x0 > x) {
                System.out.println("Bad");
                return;
            }

            x0 = x;
        }

        System.out.println("Good");
    }

}
