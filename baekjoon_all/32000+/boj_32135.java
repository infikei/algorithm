// Solve 2025-03-07

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_32135 {

    static int[] createArr(int n) {
        int[] arr = new int[n];
        int mid = (n - 1) / 2;

        arr[0] = 3;
        arr[mid] = 5;
        arr[mid + 1] = 4;
        arr[n - 1] = 6;

        int num = 1;

        for (int i = 1; i < mid; i++) {
            arr[i] = num;
            num += 2;

            if (num == 3) num += 4;
        }

        num = 2;

        for (int i = mid + 2; i < n - 1; i++) {
            arr[i] = num;
            num += 2;

            if (num == 4) num += 4;
        }

        return arr;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = createArr(n);

        StringBuilder sb = new StringBuilder();

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                // sb.append(arr[(x + y) % n]).append(' ');
                sb.append(arr[(x + y >= n) ? (x + y - n) : (x + y)]).append(' ');
            }

            sb.append('\n');
        }

        System.out.print(sb);
    }

}
