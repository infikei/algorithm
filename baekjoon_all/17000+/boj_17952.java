// Solve 2024-02-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_17952 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        ArrayDeque<int[]> taskStack = new ArrayDeque<int[]>();
        int scoreSum = 0;

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            char cmd = st.nextToken().charAt(0);

            if (cmd == '1') {
                int score = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());
                taskStack.offerLast(new int[] { score, t });
            }

            if (!taskStack.isEmpty()) {
                int[] curTask = taskStack.pollLast();

                if (--curTask[1] == 0) {
                    scoreSum += curTask[0];
                } else {
                    taskStack.offerLast(curTask);
                }
            }
        }

        System.out.println(scoreSum);
        br.close();
    }

}
