// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_1158_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        List<Integer> list = new ArrayList<Integer>();

        for (int i = 1; i <= n; i++) {
            list.add(i);
        }

        int[] ans = new int[n];
        int idx = 0;

        for (int i = 0; i < n; i++) {
            idx += k - 1;
            idx %= list.size();
            ans[i] = list.remove(idx);
        }

        StringBuilder sb = new StringBuilder();
        sb.append("<").append(ans[0]);

        for (int i = 1; i < n; i++) {
            sb.append(", ").append(ans[i]);
        }

        sb.append(">\n");
        System.out.print(sb);
        br.close();
    }

}
