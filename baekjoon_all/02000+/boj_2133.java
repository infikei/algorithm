// Solve 2025-05-27

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2133 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if (n % 2 == 1) {
            System.out.println(0);
            return;
        }

        int a = 3, s = 4;

        for (int i = 1; i < (n >> 1); i++) {
            a += s << 1;
            s += a;
        }

        System.out.println(a);
    }

}
