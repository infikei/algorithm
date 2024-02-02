// Solve 2024-02-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2961_solution1 {

    static int n;
    static int[] sour;
    static int[] bitter;
    static int minDiff;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        sour = new int[n];
        bitter = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            sour[i] = Integer.parseInt(st.nextToken());
            bitter[i] = Integer.parseInt(st.nextToken());
        }

        minDiff = Math.abs(sour[0] - bitter[0]);
        dfs(0, 1, 0);

        System.out.println(minDiff);
        br.close();
    }

    static void dfs(int depth, int sourProd, int bitterSum) {
        if (depth == n) {
            if (bitterSum == 0) return;

            int curDiff = Math.abs(sourProd - bitterSum);
            minDiff = Math.min(minDiff, curDiff);
            return;
        }

        dfs(depth + 1, sourProd, bitterSum);
        dfs(depth + 1, sourProd * sour[depth], bitterSum + bitter[depth]);
    }

}
