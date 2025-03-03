// Solve 2025-03-02

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_33556_contest151_P1_P {

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

        if (a.equals(b)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }

        if (a.equalsIgnoreCase(b)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }

}
