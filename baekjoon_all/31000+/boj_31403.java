// Solve 2024-02-09
// Update 2025-07-20

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31403 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String a = br.readLine();
        String b = br.readLine();
        int c = Integer.parseInt(br.readLine());

        System.out.println(Integer.parseInt(a) + Integer.parseInt(b) - c);
        System.out.println(Integer.parseInt(a + b) - c);
    }

}
