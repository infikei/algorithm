// Solve 2024-06-10

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_7795 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        StringTokenizer st;

        while (t-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[] a = new int[n];
            int[] b = new int[m];

            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(a);
            Arrays.sort(b);

            int ans = 0;

            for (int i = 0; i < n; i++) {
                ans += getLowerBound(b, a[i]);
            }

            sb.append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static int getLowerBound(int[] arr, int key) {
        int low = -1;
        int high = arr.length;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (arr[mid] >= key) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

}
