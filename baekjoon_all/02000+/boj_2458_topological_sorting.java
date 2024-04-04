// Solve 2024-04-04

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.BitSet;
import java.util.StringTokenizer;

public class boj_2458_topological_sorting {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] adjMat = new int[n + 1][n + 1];
        int[] inDegree = new int[n + 1];
        int[] inDegreeReversed = new int[n + 1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adjMat[a][b] = 1;
            adjMat[b][a] = -1;
            inDegree[b]++;
            inDegreeReversed[a]++;
        }

        ArrayDeque<Integer> bfsQue = new ArrayDeque<Integer>();
        ArrayDeque<Integer> bfsQueReversed = new ArrayDeque<Integer>();
        BitSet[] bitSets = new BitSet[n + 1];
        BitSet[] bitSetsReversed = new BitSet[n + 1];

        for (int u = 1; u <= n; u++) {
            if (inDegree[u] == 0) {
                bfsQue.offer(u);
            }

            if (inDegreeReversed[u] == 0) {
                bfsQueReversed.offer(u);
            }

            bitSets[u] = new BitSet(n + 1);
            bitSets[u].set(u);
            bitSetsReversed[u] = new BitSet(n + 1);
            bitSetsReversed[u].set(u);
        }

        while (!bfsQue.isEmpty()) {
            int cur = bfsQue.poll();

            for (int nxt = 1; nxt <= n; nxt++) {
                if (adjMat[cur][nxt] == 1) {
                    if (--inDegree[nxt] == 0) {
                        bfsQue.offer(nxt);
                    }

                    bitSets[nxt].or(bitSets[cur]);
                }
            }
        }

        while (!bfsQueReversed.isEmpty()) {
            int cur = bfsQueReversed.poll();

            for (int nxt = 1; nxt <= n; nxt++) {
                if (adjMat[cur][nxt] == -1) {
                    if (--inDegreeReversed[nxt] == 0) {
                        bfsQueReversed.offer(nxt);
                    }

                    bitSetsReversed[nxt].or(bitSetsReversed[cur]);
                }
            }
        }

        int ans = 0;

        for (int u = 1; u <= n; u++) {
            if (bitSets[u].cardinality() + bitSetsReversed[u].cardinality() == n + 1) {
                ans++;
            }
        }

        System.out.println(ans);
        br.close();
    }

}
