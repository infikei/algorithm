// Solve 2024-02-06

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_23309 {

    static int[] prev;
    static int[] next;

    static void add(int target, int node) {
        int targetNext = next[target];
        prev[node] = target;
        next[node] = targetNext;
        prev[targetNext] = node;
        next[target] = node;
    }

    static void remove(int node) {
        prev[next[node]] = prev[node];
        next[prev[node]] = next[node];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        prev = new int[1_000_001];
        next = new int[1_000_001];
        int headNode = Integer.parseInt(st.nextToken());
        int tailNode = headNode;
        prev[headNode] = next[headNode] = headNode;

        for (int i = 1; i < n; i++) {
            int newNode = Integer.parseInt(st.nextToken());
            add(tailNode, newNode);
            tailNode = newNode;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            String cmd = st.nextToken();

            if (cmd.equals("BN")) {
                int target = Integer.parseInt(st.nextToken());
                int node = Integer.parseInt(st.nextToken());
                sb.append(next[target]).append("\n");
                add(target, node);
            } else if (cmd.equals("BP")) {
                int target = Integer.parseInt(st.nextToken());
                int node = Integer.parseInt(st.nextToken());
                sb.append(prev[target]).append("\n");
                add(prev[target], node);
            } else if (cmd.equals("CN")) {
                int target = Integer.parseInt(st.nextToken());
                sb.append(next[target]).append("\n");
                remove(next[target]);
            } else if (cmd.equals("CP")) {
                int target = Integer.parseInt(st.nextToken());
                sb.append(prev[target]).append("\n");
                remove(prev[target]);
            }
        }

        System.out.print(sb);
        br.close();
    }

}
