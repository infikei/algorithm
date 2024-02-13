// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_10973 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] p = new int[n];

        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }

        if (prevPermutation(p)) {
            for (int i = 0; i < n; i++) {
                sb.append(p[i]).append(" ");
            }
        } else {
            sb.append("-1");
        }

        System.out.println(sb);
        br.close();
    }

    static boolean prevPermutation(int[] p) {
        int n = p.length;
        int i = n - 1;

        while (i >= 1 && p[i - 1] <= p[i]) {
            i--;
        }

        if (i == 0) return false;

        int j = n - 1;

        while (p[i - 1] <= p[j]) {
            j--;
        }

        swap(p, i - 1, j);
        j = n - 1;

        while (i < j) {
            swap(p, i++, j--);
        }

        return true;
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}
