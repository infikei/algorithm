// Solve 2024-05-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_2841 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        ArrayDeque<Integer>[] stacks = new ArrayDeque[7];

        for (int i = 1; i < 7; i++) {
            stacks[i] = new ArrayDeque<Integer>();
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            while (!stacks[x].isEmpty() && stacks[x].peekLast() > y) {
                stacks[x].pollLast();
                ans++;
            }

            if (stacks[x].isEmpty() || stacks[x].peekLast() != y) {
                stacks[x].offerLast(y);
                ans++;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
