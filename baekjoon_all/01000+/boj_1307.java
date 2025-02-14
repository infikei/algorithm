// Solve 2025-02-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1307 {

    static void printMagicSquareOdd(int n) {
        StringBuilder sb = new StringBuilder();
        int n2 = n / 2;
        int n21 = n2 + 1;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int u = (x + y + n21) % n;
                int v = (u + y + n21) % n;
                sb.append(u * n + v + 1).append(' ');
            }

            sb.append('\n');
        }

        System.out.println(sb);
    }

    static void printMagicSquare2(int n) {
        StringBuilder sb = new StringBuilder();
        int n2 = n / 2;
        int n4 = n / 4;
        int n41 = n4 + 1;

        int c3 = n2 + n4 + 2;

        int kk = n2 * n2;
        int kk2 = kk * 2;
        int kk3 = kk * 3;

        for (int x = 0; x < n4; x++) {
            for (int y = 0; y < n; y++) {
                int u = (x + y + n41) % n2;
                int v = (u + y + n41) % n2;
                int prefix = (y < n4 ? kk3 : y < n2 ? 0 : y < c3 ? kk2 : kk);
                sb.append(u * n2 + v + prefix + 1).append(' ');
            }

            sb.append('\n');
        }

        for (int y = 0; y < n; y++) {
            int u = (n4 + y + n41) % n2;
            int v = (u + y + n41) % n2;
            int prefix = (y == 0 ? 0 : y <= n4 ? kk3 : y < n2 ? 0 : y < c3 ? kk2 : kk);
            sb.append(u * n2 + v + prefix + 1).append(' ');
        }

        sb.append('\n');

        for (int x = n4 + 1; x < n2; x++) {
            for (int y = 0; y < n; y++) {
                int u = (x + y + n41) % n2;
                int v = (u + y + n41) % n2;
                int prefix = (y < n4 ? kk3 : y < n2 ? 0 : y < c3 ? kk2 : kk);
                sb.append(u * n2 + v + prefix + 1).append(' ');
            }

            sb.append('\n');
        }

        for (int x = 0; x < n4; x++) {
            for (int y = 0; y < n; y++) {
                int u = (x + y + n41) % n2;
                int v = (u + y + n41) % n2;
                int prefix = (y < n4 ? 0 : y < n2 ? kk3 : y < c3 ? kk : kk2);
                sb.append(u * n2 + v + prefix + 1).append(' ');
            }

            sb.append('\n');
        }

        for (int y = 0; y < n; y++) {
            int u = (n4 + y + n41) % n2;
            int v = (u + y + n41) % n2;
            int prefix = (y == 0 ? kk3 : y <= n4 ? 0 : y < n2 ? kk3 : y < c3 ? kk : kk2);
            sb.append(u * n2 + v + prefix + 1).append(' ');
        }

        sb.append('\n');

        for (int x = n4 + 1; x < n2; x++) {
            for (int y = 0; y < n; y++) {
                int u = (x + y + n41) % n2;
                int v = (u + y + n41) % n2;
                int prefix = (y < n4 ? 0 : y < n2 ? kk3 : y < c3 ? kk : kk2);
                sb.append(u * n2 + v + prefix + 1).append(' ');
            }

            sb.append('\n');
        }

        System.out.println(sb);
    }

    static void printMagicSquare4(int n) {
        StringBuilder sb = new StringBuilder();
        int nn1 = n * n + 1;
        int n2 = n / 2;
        int n4 = n / 4;
        int num = 0;

        for (int x = 0; x < n4; x++) {
            for (int y = 0; y < n4; y++) {
                sb.append(++num).append(' ');
            }

            for (int y = 0; y < n2; y++) {
                sb.append(nn1 - ++num).append(' ');
            }

            for (int y = 0; y < n4; y++) {
                sb.append(++num).append(' ');
            }

            sb.append('\n');
        }

        for (int x = 0; x < n2; x++) {
            for (int y = 0; y < n4; y++) {
                sb.append(nn1 - ++num).append(' ');
            }

            for (int y = 0; y < n2; y++) {
                sb.append(++num).append(' ');
            }

            for (int y = 0; y < n4; y++) {
                sb.append(nn1 - ++num).append(' ');
            }

            sb.append('\n');
        }

        for (int x = 0; x < n4; x++) {
            for (int y = 0; y < n4; y++) {
                sb.append(++num).append(' ');
            }

            for (int y = 0; y < n2; y++) {
                sb.append(nn1 - ++num).append(' ');
            }

            for (int y = 0; y < n4; y++) {
                sb.append(++num).append(' ');
            }

            sb.append('\n');
        }

        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if (n % 2 == 1) {
            printMagicSquareOdd(n);
        } else if (n % 4 == 0) {
            printMagicSquare4(n);
        } else {
            printMagicSquare2(n);
        }
    }

}
