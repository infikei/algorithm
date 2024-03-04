// Solve 2024-03-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_5639 {

    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        int n = 0;
        int[] preOrder = new int[10000];

        while (true) {
            String s = br.readLine();

            if (s == null || s.equals("")) break;

            preOrder[n++] = Integer.parseInt(s);
        }

        getPostOrder(preOrder, 0, n - 1);
        System.out.print(sb);
        br.close();
    }

    static void getPostOrder(int[] preOrder, int begin, int end) {
        if (begin > end) return;

        int mid = upperBound(preOrder, begin + 1, end, preOrder[begin]);
        getPostOrder(preOrder, begin + 1, mid - 1);
        getPostOrder(preOrder, mid, end);
        sb.append(preOrder[begin]).append("\n");
    }

    static int upperBound(int[] arr, int begin, int end, int key) {
        int low = begin - 1;
        int high = end + 1;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (arr[mid] > key) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

}
