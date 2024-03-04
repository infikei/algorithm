// Solve 2024-03-03

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_1326 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] bridge = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 1; i <= n; i++) {
            bridge[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        boolean[] visited = new boolean[n + 1];
        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
        int ansJumpCount = -1;
        int curJumpCount = 0;

        if (a == b) {
            ansJumpCount = 0;
        } else {
            visited[a] = true;
            bfsQue.offer(a);
        }

        while (!bfsQue.isEmpty()) {
            curJumpCount++;
            int curIter = bfsQue.size();

            while (curIter-- > 0) {
                int curPos = bfsQue.poll();

                if (bridge[curPos] == 0) continue;

                for (int nextPos = curPos - bridge[curPos]; nextPos >= 1; nextPos -= bridge[curPos]) {
                    if (nextPos == b) {
                        ansJumpCount = curJumpCount;
                        break;
                    } else if (!visited[nextPos]) {
                        visited[nextPos] = true;
                        bfsQue.offer(nextPos);
                    }
                }

                if (ansJumpCount != -1) break;

                for (int nextPos = curPos + bridge[curPos]; nextPos <= n; nextPos += bridge[curPos]) {
                    if (nextPos == b) {
                        ansJumpCount = curJumpCount;
                        break;
                    } else if (!visited[nextPos]) {
                        visited[nextPos] = true;
                        bfsQue.offer(nextPos);
                    }
                }

                if (ansJumpCount != -1) break;
            }

            if (ansJumpCount != -1) break;
        }

        System.out.println(ansJumpCount);
        br.close();
    }

}
