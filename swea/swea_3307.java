// Solve 2024-03-27

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_3307 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        int[] numbers = new int[1000];
        int[] memo = new int[1000];
        int memoLen = 0;

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < n; i++) {
                numbers[i] = Integer.parseInt(st.nextToken());
            }

            memoLen = 0;

            for (int i = 0; i < n; i++) {
                int idx = upperBound(memo, memoLen, numbers[i]);

                if (idx == memoLen) {
                    memo[memoLen++] = numbers[i];
                } else {
                    memo[idx] = numbers[i];
                }
            }

            sb.append("#").append(ti).append(" ").append(memoLen).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static int upperBound(int[] arr, int arrSize, int keyValue) {
        int low = -1;
        int high = arrSize;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (arr[mid] > keyValue) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

}
