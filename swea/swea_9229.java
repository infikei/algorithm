// Solve 2024-02-06

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class swea_9229 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine(), " ");
            List<Integer> list = new ArrayList<Integer>(n);

            for (int i = 0; i < n; i++) {
                list.add(Integer.parseInt(st.nextToken()));
            }

            Collections.sort(list);
            int ans = -1;
            int i = 0;
            int j = n - 1;

            while (i < j) {
                int val = list.get(i) + list.get(j);

                if (val <= m) {
                    ans = Math.max(ans, val);
                    i++;
                } else {
                    j--;
                }
            }

            sb.append("#").append(ti).append(" ").append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
