// Solve 2025-03-02
// Update 2025-07-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P1_P_boj_33556 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String a = br.readLine();
        String b = br.readLine();

        if (a.equals("null")) {
            System.out.println("NullPointerException");
            System.out.println("NullPointerException");
            return;
        }

        if (b.equals("null")) {
            b = null;
        }

        System.out.println(a.equals(b) ? "true" : "false");
        System.out.println(a.equalsIgnoreCase(b) ? "true" : "false");
    }

}
