// Solve 2024-01-31
// Update 2024-02-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_15650_nextpermutation {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] selected = new int[n];

        for (int i = m; i < n; i++) {
            selected[i] = 1;
        }

        do {
            for (int i = 0; i < n; i++) {
                if (selected[i] == 0) {
                    sb.append(i + 1).append(" ");
                }
            }

            sb.append("\n");
        } while (nextPermutation(selected));

        System.out.print(sb);
        br.close();
    }

    static boolean nextPermutation(int[] arr) {
        int n = arr.length;
        int i = n - 1;

        while (i >= 1 && arr[i - 1] >= arr[i]) {
            i--;
        }

        if (i == 0) return false;

        int j = n - 1;

        while (arr[i - 1] >= arr[j]) {
            j--;
        }

        swap(arr, i - 1, j);
        j = n - 1;

        while (i < j) {
            swap(arr, i++, j--);
        }

        return true;
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}
