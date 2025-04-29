// Solve 2025-04-29

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_22866 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] building = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 1; i <= n; i++) {
            building[i] = Integer.parseInt(st.nextToken());
        }

        int[][] ans = new int[n + 1][2];

        for (int i = 1; i <= n; i++) {
            ans[i][1] = -1;
        }

        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

        for (int i = 1; i <= n; i++) {
            while (!stack.isEmpty() && building[stack.peekLast()] <= building[i]) {
                stack.pollLast();
            }

            if (!stack.isEmpty()) {
                ans[i][0] += stack.size();
                ans[i][1] = stack.peekLast();
            }

            stack.addLast(i);
        }

        stack.clear();

        for (int i = n; i >= 1; i--) {
            while (!stack.isEmpty() && building[stack.peekLast()] <= building[i]) {
                stack.pollLast();
            }

            if (!stack.isEmpty()) {
                ans[i][0] += stack.size();
                ans[i][1] = chooseNearestBulidingNum(i, ans[i][1], stack.peekLast());
            }

            stack.addLast(i);
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            if (ans[i][0] == 0) {
                sb.append(0).append('\n');
            } else {
                sb.append(ans[i][0]).append(' ').append(ans[i][1]).append('\n');
            }
        }

        System.out.print(sb);
    }

    static int chooseNearestBulidingNum(int cur, int left, int right) {
        if (left == -1) return right;

        int leftDist = cur - left;
        int rightDist = right - cur;

        if (leftDist > rightDist) return right;

        return left;
    }

}
