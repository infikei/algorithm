// Solve 2024-02-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1182 {

    static int n, s, ans;
    static int[] arr;

    static void recur(int depth, int sum, int cnt) {
        if (depth == n) {
            if (sum == s && cnt > 0) {
                ans++;
            }

            return;
        }

        recur(depth + 1, sum, cnt);
        recur(depth + 1, sum + arr[depth], cnt + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        recur(0, 0, 0);

        System.out.println(ans);
        br.close();
    }

}
