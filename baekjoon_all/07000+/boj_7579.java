// Solve 2024-03-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_7579 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] memory = new int[n];
        int[] cost = new int[n];

        st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < n; i++) {
            memory[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < n; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
        }

        int[] memo = new int[10001];

        for (int i = 0; i < n; i++) {
            for (int j = 10000; j >= cost[i]; j--) {
                memo[j] = Math.max(memo[j], memo[j - cost[i]] + memory[i]);
            }
        }

        int idx = lowerBound(memo, 10001, m);
        System.out.println(idx);
        br.close();
    }

    static int lowerBound(int[] arr, int arrSize, int keyValue) {
        int low = -1;
        int high = arrSize;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (arr[mid] >= keyValue) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

}
