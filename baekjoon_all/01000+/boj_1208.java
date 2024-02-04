// Solve 2024-02-04

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class boj_1208 {

    static int n, s;
    static long ans;
    static int[] arr;
    static Map<Integer, Long> map;

    static void recur(int depth, int sum) {
        if (depth == (n >> 1)) {
            if (map.get(sum) == null) {
                map.put(sum, 1L);
            } else {
                map.put(sum, map.get(sum) + 1L);
            }

            return;
        }

        recur(depth + 1, sum);
        recur(depth + 1, sum + arr[depth]);
    }

    static void recur2(int depth, int sum) {
        if (depth == n) {
            if (map.get(s - sum) != null) {
                ans += map.get(s - sum);
            }

            return;
        }

        recur2(depth + 1, sum);
        recur2(depth + 1, sum + arr[depth]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        map = new HashMap<Integer, Long>();
        recur(0, 0);
        recur2(n >> 1, 0);

        if (s == 0) ans--;

        System.out.println(ans);
        br.close();
    }

}
