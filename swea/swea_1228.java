// Solve 2024-02-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class swea_1228 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        for (int ti = 1; ti <= 10; ti++) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), " ");
            List<String> list = new LinkedList<String>();

            for (int i = 0; i < n; i++) {
                list.add(st.nextToken());
            }

            int k = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), " ");

            while (k-- > 0) {
                st.nextToken();
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                while (y-- > 0) {
                    list.add(x++, st.nextToken());
                }
            }

            sb.append("#").append(ti);

            for (int i = 0; i < 10; i++) {
                sb.append(" ").append(list.get(i));
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
