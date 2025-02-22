// Solve 2024-01-28
// Update 2025-02-21

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1654 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[] lengths = new int[k];

        for (int i = 0; i < k; i++) {
            lengths[i] = Integer.parseInt(br.readLine());
        }

        long low = 1L;
        long high = (1L << 31);

        while (low + 1 < high) {
            long mid = (low + high) / 2;
            long val = 0L;

            for (int length : lengths) {
                val += length / mid;
            }

            if (val >= n) {
                low = mid;
            } else {
                high = mid;
            }
        }

        System.out.println(low);
    }

}
