// Solve 2024-02-13

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_16435_solution3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        int[] heights = new int[n];

        for (int i = 0; i < n; i++) {
            heights[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(heights);
        int left = -1;

        while (true) {
            int nextLeft = binarySearch(heights, left, n, l);

            if (left == nextLeft) break;

            l += nextLeft - left;
            left = nextLeft;
        }

        System.out.println(l);
        br.close();
    }

    static int binarySearch(int[] arr, int low, int high, int value) {
        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (arr[mid] <= value) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }

}
