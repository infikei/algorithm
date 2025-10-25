// Solve 2025-10-25

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1541 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int ans = 0;
        int tmp = 0;
        boolean minus = false;

        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);

            if (c == '+' || c == '-') {
                ans += (minus ? -tmp : tmp);
                tmp = 0;

                if (c == '-') minus = true;
            } else {
                tmp = tmp * 10 + (c - '0');
            }
        }

        ans += (minus ? -tmp : tmp);
        System.out.println(ans);
    }

}
